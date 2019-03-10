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
int isPalind(){
    int res=1;
    struct node * fast=start, * slow=start , *prev_slow=start, *midnode=NULL;
    if ((fast!=NULL) && (fast->link!=NULL)){
        while((fast!=NULL) && (fast->link!=NULL)){
            fast=fast->link->link;
            prev_slow=slow;
            slow=slow->link;
        }
        if (fast!=NULL){
            midnode=slow;
            slow=slow->link;
        }
        prev_slow->link=NULL;
        reverse(&slow);
        res=compare(start,slow);
        reverse(&slow);
        if(midnode!=NULL){
            prev_slow->link=midnode;
            midnode->link=slow;
        }
        else{
            prev_slow->link=slow;
        }
    }
    return res;
}
void reverse(struct node ** slow){
    struct node * prev, *next ,*current;
    current=*slow;
    prev=NULL;
    while(current!=NULL){
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    *slow=prev;
}
int compare(struct node * first,struct node * second){
    while((first!=NULL)&&(second!=NULL)){
        if(first->data==second->data){
            first=first->link;
            second=second->link;
        }
        else{
            return 0;
        }
    }
    if (first == NULL && second == NULL){
        return 1;
    }
    return 0;
}
int main()
{   int a;
    struct node * head=start;
    while(1){
        printf("\n1.Enter the node \n2. check palindrome \nEnter option : ");
        scanf("%d",&a);
        switch(a){
            case 1:insertnode();break;
            case 2:if(isPalind()==1){
                printf("\nPalindrome");
            }
            else{
                printf("\nNot Palindrome");
            };break;
            default: exit(0);
        }
    }
}

    
