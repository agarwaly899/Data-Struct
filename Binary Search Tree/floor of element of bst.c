#include <stdio.h>

#include<stdlib.h>

struct treenode {

	int data;

	struct treenode * left;

	struct treenode * right;

};

struct treenode * root=NULL;

struct treenode * create(){

	struct treenode * n;

	n=(struct treenode *)malloc(sizeof(struct treenode));

	return n;

}

void insert(){

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

void preorder(struct treenode * start){

	if(start!=NULL){

		printf("%d ",start->data);

		preorder(start->left);

		preorder(start->right);

	}

}

struct treenode * answer;

int min;

struct treenode * floors(struct treenode * start,int key){

	if(start==NULL){

		return NULL;

	}

	int temp=key-start->data;

	if ((temp<=min)&&(temp>=0)){

			min=temp;

			answer=start;

		}

		if(key<start->data){

			return floors(start->left,key);

		}

		else if(key>start->data){

			return floors(start->right,key);

		}

	}



int main(){

	int key;

	for (int i=0;i<8;i++){

		insert();

	}

	printf("\nPreorder :");

	preorder(root);

	printf("\nEnter item to find :");

	scanf("%d",&key);

	min=key-root->data;

	floors(root,key);

	printf("\nFloor is %d",answer->data);

	return 0;

}