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
int maxdepth(binarynode * node){
    if(node==NULL){
        return 0;
    }
    int ldepth=maxdepth(node->left);
    int rdepth=maxdepth(node->right);
    if(ldepth>rdepth){
        return(ldepth+1);
    }
    else {
        return (rdepth+1);
    }
}
int main()
{ 
binarynode *root;
root=create();
printf("\nHeight is : %d",maxdepth(root));
}