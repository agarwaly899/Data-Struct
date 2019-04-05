#include <stdio.h>
#include<stdlib.h>
//This program is calculating the sum of all elements greater than kth largest element
/*First max valued node is found than data is stored in some variable , then 2nd largest data is found by traversing in right->data->left manner
and update the variable by adding that 2nd largest node and so on...... till the value of k 
given by the user*/
struct treenode { 								//structure for treenode
	int data;
	struct treenode * left;
	struct treenode * right;
};
struct treenode * root=NULL; 							//initially root node is null
struct treenode * create(){ 							//creating new node for tree
	struct treenode * n;
	n=(struct treenode *)malloc(sizeof(struct treenode));
	return n;
}
void insert(){ //inserting node in tree
	struct treenode * temp;
	int data;
	temp=create();
	printf("\nEnter the data :");
	scanf("%d",&data);
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	if (root==NULL){
		root=temp;
	}
	else {
		struct treenode * par;
		par=root;
		while(par!=NULL){
			if(data < par->data){
				if(par->left==NULL){
					par->left=temp;
				}
				par=par->left;
			}
			else if(data > par->data){
				if(par->right==NULL){
					par->right=temp;
				}
				par=par->right;
			}
			else {
				par=NULL;
			}
		}
	}
	return ;
}
void preorder(struct treenode * start){ 					//preorder traversal of tree
	if(start!=NULL){
		printf("%d ",start->data);
		preorder(start->left);
		preorder(start->right);
	}
}
int sum=0,count;
void  traverse(struct treenode * start){
	if(start==NULL){
			return ;
		}
		traverse(start->right);
		if(count>1){
			sum=sum+start->data;
			count--;
		}
		traverse(start->left);
}

int main(){
	int k=2;
	for (int i=0;i<8;i++){
		insert();
	}
	printf("\nPreorder :");
	preorder(root);  
	printf("\nEnter k for kth largest no. sum:");
	scanf("%d",&k);
	while(k<=1){								//checking wheteher k is greater than 2 or not
	printf("\nEnter proper value of k :");
	scanf("%d",&k);
	}
	count=k;
	traverse(root); 
	printf("\nAnswer is %d",sum);  							//preorder traversal
	return 0;
}
