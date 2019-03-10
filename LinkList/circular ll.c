/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/



#include <stdio.h>
struct node {
    int data;
    struct node * link;
};
struct node * start=NULL;
struct node * createnode(){
    struct node * n;
    n=(struct node *) malloc(sizeof(struct node));
    return n;
}
void insertnode(){
    int item;
    struct node * temp,*t;
    printf("\nEnter the item :");
    scanf("%d",&item);
    temp=createnode();
    temp->data=item;
    temp->link=start;
    if (start==NULL){
        temp->link=temp;
    }
    else{
        t=start;
        while(t->link!=start){
           t=t->link; 
        }
        t->link=temp;
    }
    start=temp;
}
void print(){
    struct node * n;
    n=start;
    if(start!=NULL){
        do{
        printf("%d ",n->data);
        n=n->link;
        }
        while(n!=start);
    }
}
int main()
{   int a;
    while(1){
        printf("\n1.Enter the node\n2. Print\nEnter option : ");
        scanf("%d",&a);
        switch(a){
            case 1:insertnode();break;
            case 2:print();break;
            default: exit(0);
        }
    }
}

    
