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
//deletion in a binary search tree
 // 1,the node is leaf node
    // search the node and delete the node
 // 2,the node is not a leaf node
    // comes a picture of inorder predecessor or inorder succesor
    // inorder predecessor = largest value in left subtree
    // inorder successor = largest value in right subtree
 // 3,the node is the root node or node in bw BST
    //search for the node
    //search for inorder, preorder or postorder
    //keep doing this until the tree has no empty nodes

struct node* inorderPredecessor(struct node* root){
    // inorder predecessor is right most child of left subtree
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}

struct node* deletenode(struct node* root,int value){
    struct node* ipre;
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    //search for the node to be deleted
    if(value<root->data){
        root->left=deletenode(root->left,value);
    }
    else if(value>root->data){
        root->right=deletenode(root->right,value);
    }
    //deletion startegy when the node is found
    else{
        ipre=inorderPredecessor(root);      //Find the inorder predecessor
        root->data=ipre->data;              //Copy predecessor → root->data = ipre->data
        root->left=deletenode(root->left,ipre->data);      //Delete the predecessor from left subtree:
    }
    return root;
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

    deletenode(p,6);

    return 0;
}
