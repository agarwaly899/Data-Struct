/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
struct treenode{
    int data;
    struct treenode * left;
    struct treenode * right;
};
struct treenode * root=NULL;
void insert(){
    int data;
    struct treenode * n;
    struct treenode * par;
    printf("Enter the data :");
    scanf(" %d",&data);
    n=(struct treenode *)malloc(sizeof(struct treenode));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    if(root==NULL){
        root=n;
    }
    else {
        par=root;
        while(par!=NULL){
            if(par->data>data){
                if(par->left==NULL){
                    par->left=n;
                }
                par=par->left;
            }
            else if(par->data<data){
                if(par->right==NULL){
                    par->right=n;
                }
                par=par->right;
            }
            else {
                par=NULL;
            }
        }
    }
}
void preorder(struct treenode * root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
struct treenode * find(struct treenode * start,int data){
    
    if (start==NULL){
        return NULL;
    }
    if(data<start->data){
        return (find(start->left,data));
    }
    else if(data>start->data){
        return (find(start->right,data));
    }
    return start;
}
int main(){   
    struct treenode * temp;
    int data;
    
    for (int i=0;i<8;i++){
        insert();
    }
    printf("\nPreorder :");
    preorder(root);
    printf("\nEnter data to find :");
    scanf(" %d",&data);
    temp=find(root,data);
    if (temp->data==data){
        printf("\nElement exist.");
    }
    else {
        printf("\nElement not exist.");
    }
    return 0;
}
