#include<stdio.h> 
#include<stdlib.h> 
struct treenode 
{ 
    int data; 
    struct treenode *left; 
    struct treenode *right; 
    int height; 
}; 
int height(struct treenode *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->height; 
} 
int max(int a, int b) 
{ 
    return (a > b)?a:b; 
} 
struct treenode* newNode(int key) 
{ 
    struct treenode* node = (struct treenode*) 
                        malloc(sizeof(struct treenode)); 
    node->data  = key; 
    node->left   = NULL; 
    node->right  = NULL; 
    node->height = 1; 
    return(node); 
}
int getBalance(struct treenode *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
}
struct treenode * leftrotate(struct treenode * x){
    struct treenode * y=x->right;
    struct treenode * t2=y->left;
        y->left=x;
        x->right=t2;
    y->height=1+max(height(y->left),height(y->right));
    x->height=1+max(height(x->left),height(x->right));
    return y;
}
struct treenode * rightrotate(struct treenode * x){
    struct treenode * y=x->left;
    struct treenode * t2=y->right;
        y->right=x;
        x->left=t2;
    y->height=1+max(height(y->left),height(y->right));
    x->height=1+max(height(x->left),height(x->right));
    return y;
}
struct treenode * insert(struct treenode * start,int data){
    struct treenode * n;
    n=newNode(data);
    if(start==NULL){
        start=n;
    }
    if(data<start->data){
        start->left=insert(start->left,data);
    }
    else if(data>start->data){
        start->right=insert(start->right,data);
    }
    else {
        return start;
    }
    start->height=1+max(height(start->left),height(start->right));
    int balance=getBalance(start);
    if (balance>1 && data<start->left->data){
        return rightrotate(start);
    }
    else if (balance>1 && data>start->left->data){
        start->left=leftrotate(start->left);
        rightrotate(start);
    }
    else if (balance<-1 && data>start->right->data){
        return leftrotate(start);
    }
    else if (balance<-1 && data<start->right->data){
        start->right=rightrotate(start->left);
        leftrotate(start);
    }
    return start;
}
void preorder(struct treenode *root) 
{ 
    if(root != NULL) 
    { 
        printf("%d ", root->data); 
        preorder(root->left); 
        preorder(root->right); 
    } 
}
int main(){
    int data;
    struct treenode * root=NULL;
    for (int i=0;i<6;i++){
    printf("\nEnter the data:");
    scanf("%d",&data);
    root=insert(root,data);
    }
    printf("\npreorder of avl :");
    preorder(root);
}