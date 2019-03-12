#include <stdio.h>
int count=0;
typedef struct treenode
{
int data;
struct treenode *left;
struct treenode *right;
} binarynode;
binarynode *create()
{
binarynode *p;
int x;
printf("\nEnter data (-1 for end):");
scanf("%d",&x);
if(x== -1)
return NULL;
p=(binarynode*)malloc(sizeof(binarynode));
p->data=x;
/* to insert left child */
printf("\nEnter left child of %d:\n",x);
p->left=create();
/* To insert right child */
printf("\nEnter right child of %d:\n",x);
p->right=create();
return p; //return the created tree root
}
void preorder(binarynode * node){
    if(node!=NULL){
        if((node->left!=NULL)||(node->right!=NULL)){
            count++;
        }
        preorder(node->left);
        preorder(node->right);
    }
}
int main()
{ 
binarynode *root;
root=create();
preorder(root);
printf("\nNo. of non leaf nodes : %d",count);
}