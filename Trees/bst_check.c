// Check whether a binary tree is a BST
#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createNode(int data){
    struct node *n;                   
    n = (struct node *) malloc(sizeof(struct node));             
    n->data = data;                    
    n->left = NULL;                    
    n->right = NULL;                
    return n;                      
}

int isBSTUtil(struct node* root, struct node* min, struct node* max) {
    if (root == NULL) return 1;
    
    if (min != NULL && root->data <= min->data) return 0;
    if (max != NULL && root->data >= max->data) return 0;
    
    return isBSTUtil(root->left, min, root) && 
           isBSTUtil(root->right, root, max);
}

int isBST(struct node* root) {
    return isBSTUtil(root, NULL, NULL);
}
int main(){
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
   
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    if(isBST(p)){
        printf("This is a bst" );
    }
    else{
        printf("This is not a bst");
    }
    return 0;
}
