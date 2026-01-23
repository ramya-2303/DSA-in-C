//Implementation of Expression trees
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>      //ctype.h → for isalnum() → checks if a character is A-Z / a-z / 0-9
#include <math.h>

//STRUCTURE OF EXPRESSION TREE NODE
typedef struct node {
    char data;
    struct node *left, *right;   
} node;

node* newNode(char data) {
    node* n = (node*) malloc(sizeof(node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

typedef struct {
    node* arr[100];
    int top;
} NodeStack;

void pushNode(NodeStack *s, node *x)
 {
     s->arr[++s->top] = x;
 }

node* popNode(NodeStack *s) 
{ 
    return s->arr[s->top--]; 
}

char opStack[100];     //satck for operators infix to postfix
int opTop = -1;

void pushOp(char c) { 
  opStack[++opTop] = c; 
}
char popOp() {
  return opStack[opTop--];
}
char peekOp() { 
  return opStack[opTop]; 
}

int precedence(char op) {
    if (op == '^') 
      return 3;
    if (op == '*' || op == '/') 
      return 2;
    if (op == '+' || op == '-')
      return 1;
    return 0;
}

int isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;   // i->index of infix
                    // j->index of postfix

    for (i = 0; infix[i] != '\0'; i++) {    
        char c = infix[i];   

        if (c == ' ')
            continue;      

        if (isalnum(c)) {
            postfix[j++] = c;      
                                 
        }
        else if (c == '(') {
            pushOp(c);
        }
        else if (c == ')') {
            while (opTop != -1 && peekOp() != '(')
                postfix[j++] = popOp();
            popOp();    // remove '('
        }
        else if (isOperator(c)) {
            while (opTop != -1 && precedence(peekOp()) >= precedence(c))
                postfix[j++] = popOp();
            pushOp(c);
// A + B * C
// When you see +, stack empty → push
// When you see *, has higher precedence than + → push
// When you see last operator, pop accordingly.
        }
    }

    while (opTop != -1)
        postfix[j++] = popOp();    
    postfix[j] = '\0';             
}

node* constructTree(char postfix[]) {
    NodeStack s;
    s.top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char t = postfix[i];                   

        if (!isOperator(t)) {
            pushNode(&s, newNode(t));
        } else {
            node *root = newNode(t);
            root->right = popNode(&s);
            root->left  = popNode(&s);
            pushNode(&s, root);
        }
    }
    return popNode(&s);
}

float compute(float L, float R, char op) {
    switch (op) {
        case '+': return L + R;
        case '-': return L - R;
        case '*': return L * R;
        case '/': return L / R;
        case '^': return pow(L, R);
    }
    return 0;
}

//evaluate entire expression tree by recursion
float eval(node *root) {
    if (!root) return 0;

    if (!isOperator(root->data))
        return root->data - '0';    

    float L = eval(root->left);
    float R = eval(root->right);

    return compute(L, R, root->data);
}

void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

void preorder(node *root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

int main() {
    char infix[100], postfix[100];

    printf("Enter INFIX expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("\nPOSTFIX : %s\n", postfix);

    node *root = constructTree(postfix);

    printf("\nInorder (Infix)   : ");
    inorder(root);

    printf("\nPreorder (Prefix) : ");
    preorder(root);

    printf("\nPostorder         : ");
    postorder(root);

    float result = eval(root);
    printf("\n\nEvaluated Result = %.2f\n", result);

    return 0;
}
