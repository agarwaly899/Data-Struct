/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/



#include <stdio.h>
int count=0;
struct node {
    int data;
    struct node * next;
    struct node * prev;
};
struct node * start=NULL;
struct node * createnode(){
    struct node * n;
    n=(struct node *) malloc(sizeof(struct node));
    count++;
    return n;
}
void insertnode(){
    int item;
    struct node * temp,*t;
    printf("\nEnter the item :");
    scanf("%d",&item);
    temp=createnode();
    temp->prev=NULL;
    temp->data=item;
    temp->next=NULL;
    if (start==NULL){
        start=temp;
    }
    else{
        t=start;
        while(t->next!=NULL){
           t=t->next; 
        }
        t->next=temp;
        temp->prev=t;
    }
}
void insertbtw(){
    struct node * n, *k;
    int posit;
    n=createnode();
    printf("Enter the position :");
    scanf("%d",&posit);
    n->prev=NULL;
    n->next=NULL;
    if(posit<2){
        printf("Enter the item:");
        scanf("%d",&n->data);
        n->next=start;
        start->prev=n;
        n->prev=NULL;
        start=n;
    }
    else if((posit<count)&&(posit>=2)){
        printf("Enter the item:");
        scanf("%d",&n->data);
        k=start;
        for(int i=2;i<posit;i++){
            k=k->next;
        }
        n->prev=k;
        n->next=k->next;
        k->next->prev=n;
        k->next=n;
    }
    else {
        insertnode();
    }
    
}
void print(){
    struct node * n;
    n=start;
    while(n!=NULL){
        printf("%d ",n->data);
        n=n->next;
    }
}
int main()
{   int a;
    while(1){
        printf("\n1.Enter the node\n2. Print\n3. Insert Between\nEnter option : ");
        scanf("%d",&a);
        switch(a){
            case 1:insertnode();break;
            case 2:print();break;
            case 3:insertbtw();break;
            default: exit(0);
        }
    }
}

    
