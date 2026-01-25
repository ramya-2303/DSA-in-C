//Implementation of threaded binary trees usinng C
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
    int lthread, rthread;   // 1 = thread, 0 = child
};

// Function to find inorder successor
struct node* inorder_successor(struct node* ptr) {
    if (ptr->rthread == 1)
        return ptr->right;        
    ptr = ptr->right;             
  while (ptr->lthread == 0)
        ptr = ptr->left;        
    return ptr;
}

// Insert into Threaded BST
struct node* insert(struct node* root, int key) {
    struct node *ptr = root;   
    struct node *par = NULL;    

   while (ptr != NULL) {
        if (key == ptr->data) {
            printf("Duplicate key!\n");
            return root;
        }
        par = ptr;                  
        if (key < ptr->data) {
            if (ptr->lthread == 0)
                ptr = ptr->left;     
            else
                break;            
        } 
        else {
            if (ptr->rthread == 0)
                ptr = ptr->right;    
            else
                break;               
        }
    }

    // Create the new node
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = key;
    temp->lthread = temp->rthread = 1;  

    // Case 1: Tree is empty
    if (par == NULL) {
        root = temp;
        temp->left = temp->right = NULL;    
    }

    // Case 2: Insert as left child
    else if (key < par->data) {
        temp->left = par->left;   
        temp->right = par;       
        par->lthread = 0;         
        par->left = temp;
    }

    // Case 3: Insert as right child
    else {
        temp->right = par->right;
        temp->left = par;          
        par->rthread = 0;         
        par->right = temp;
    }

    return root;
}

void inorder(struct node* root) {
    if (root == NULL)
        return;

    struct node* ptr = root;

    while (ptr->lthread == 0)
        ptr = ptr->left;

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = inorder_successor(ptr);
    }
}

int main() {
    struct node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder Traversal of Threaded BST: ");
    inorder(root);

    return 0;
}
