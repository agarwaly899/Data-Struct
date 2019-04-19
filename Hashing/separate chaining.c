/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define size 10
struct hash {
    int data;
    struct hash * next;
};
int hashing(int key){
    int index=key%size;
    return index;
}
struct hash * create(){
    struct hash * n;
    n=(struct hash *)malloc(sizeof(struct hash));
    return n;
}
void insert(int key,struct hash table[]){
    int index=hashing(key);
    struct hash * second=create();
    second->data=-1;
    second->next=NULL;
    if(table[index].data!=key){
        struct hash * current=&table[index];
        while(current->data!=-1){
            current=current->next;
        }
        current->data=key;
        current->next=second;
        printf("\nInserted!!");
        return;
    }
    table[index].data=key;
    printf("\nInserted!!");
}
void find(int key,struct hash table[]){
    int index=hashing(key);
    struct hash * current=&table[index];
    while(current->data!=key){
        if(current->data==-1){
            printf("\nNot found!");
            return;
        }
        current=current->next;
    }
    printf("\nFound!!");
}
void print(struct hash table[]){
    struct hash * current;
    printf("\nHash Table:");
    for (int i=0;i<size;i++){
        printf("\n");
        current=&table[i];
        while(current!=NULL){
            printf("%d->",current->data);
            current=current->next;
        }
        printf("NULL");
    }
}
int main(){
    int n,key;
    struct hash table[size];
    for (int i=0;i<size;i++){
        table[i].data=-1;
        table[i].next=NULL;
    }
    while(1){
        printf("\n1.Insert\n2.Find");
        printf("\nChoose the option :");
        scanf("%d",&n);
        if(n==1){
            printf("\nEnter the element :");
            scanf("%d",&key);
            if (key>=0){
                insert(key,table);
                print(table);
            }
            else {
                printf("\nPositive no.s only!!");
            }
        }
        else if(n==2){
            printf("\nEnter the element :");
            scanf("%d",&key);
            if(key>=0){
                find(key,table);
                print(table);
            }
            else {
                printf("\nPositive no.s only!!");
            }
        }
        else {
            break;
        }
    }
    return 0;
}
