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
void count(){
    int key;
    int count=0;
    struct node * temp;
    temp=start;
    printf("\nEnter the key : ");
    scanf("%d",&key);
    while(temp!=NULL){
        if((temp->data)==key){
            count++;
        }
        temp=temp->link;
    }
    printf("\n%d appears %d times!!",key,count);
}
void deletenode(){
    int key;
    struct node * temp,* prev=start;
    printf("\nEnter no. to delete node :");
    scanf("%d",&key);
    if(start!=NULL){
        if(start->data==key){
            temp=start;
            start=start->link;
            printf("Done!");
            return;
        }
        else {
            temp=prev->link;
            while(temp!=NULL){
                if(temp->data==key){
                    prev->link=temp->link;
                    free(temp);
                    printf("Done!");
                    return;
                }
                prev=prev->link;
                temp=temp->link;
            }
        }
    }
    printf("\nNo such data found!");
}
void printlist(struct node * begin){
    while (begin!=NULL){
       printf("%d->",begin->data);
       begin=begin->link;
    }
    printf("null");
}
int main()
{   int a;
    while(1){
        printf("\n1.Enter the node \n2. Search \n3. Delete node\n4. Print list \nEnter option : ");
        scanf("%d",&a);
        switch(a){
            case 1:insertnode();break;
            case 2:count();break;
		    case 3:deletenode();break;
		    case 4:printlist(start);break;
            default: exit(0);
        }
    }
}

    