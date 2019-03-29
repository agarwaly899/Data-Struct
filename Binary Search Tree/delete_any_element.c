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

struct treenode * findmax(struct treenode * start){
    while(start->right!=NULL){
        start=start->right;
    }
    return start;
}
struct treenode * delete(struct treenode * start,int key){
    struct treenode * temp;
    if(start==NULL){
        printf("\nNo such Element.");
        return NULL;
    }
    else if(key<start->data){
        start->left=delete(start->left,key);
    }
    else if(key>start->data){
        start->right=delete(start->right,key);
    }
    else{
        if((start->right!=NULL)&&(start->left!=NULL)){
            temp=findmax(start->left);
            start->data=temp->data;
            start->left=delete(start->left,start->data);
        }
        else{
            temp=start;
            if(start->left==NULL){
                start=start->right;
            }
            else if(start->right==NULL){
                start=start->left;
            }
            free(temp);
        }
    } 
    return start;
}
int main(){   
    struct treenode * temp;
    int data,del;
    
    for (int i=0;i<8;i++){
        insert();
    }
    printf("\nPreorder :");
    preorder(root);
    while(del>=0){
    printf("\nEnter item to delete :");
    scanf("%d",&del);
    temp=delete(root,del);
    printf("\nPreorder :");
    preorder(temp);
    }
    return 0;
}