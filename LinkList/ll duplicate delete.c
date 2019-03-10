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
    temp->link=NULL;
    if (start==NULL){
        start=temp;
    }
    else{
        t=start;
        while(t->link!=NULL){
           t=t->link; 
        }
        t->link=temp;
    }
}
void delete(){
   struct node * n,*m,*k,*hold=NULL;
   n=start;
   while(n!=NULL){
       m=n->link;
       k=n;
       while(m!=NULL){
            if(m->data==n->data){
                hold=m;
                k->link=m->link;
                m=m->link;
                free(hold);
                continue;
            }
            k=k->link;
            m=m->link;
       }
       n=n->link;
   }
}
void print(){
    struct node * n;
    n=start;
    while(n!=NULL){
        printf("%d->",n->data);
        n=n->link;
    }
    printf("NULL");
}
int main()
{   int a;
    while(1){
        printf("\n1.Enter the node\n2. Delete duplicates\n3. Print\nEnter option : ");
        scanf("%d",&a);
        switch(a){
            case 1:insertnode();break;
            case 2:delete();break;
            case 3:print();break;
            default: exit(0);
        }
    }
}

    
