/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define size 10
struct hash {
    int data;    
};
int hashing(int key){
    int index=key%size;
    return index;
}
void insert(int key,struct hash table[]){
    int index=hashing(key);
    if(table[index].data!=key){
        while(table[index].data!=-1){
            index=(index+1)%size;
            if(index==hashing(key)){
                printf("\nHash table full!!");
                return;
            }
        }
    }
    table[index].data=key;
    printf("\nInserted!!");
}
void find(int key,struct hash table[]){
    int index=hashing(key);
    while(table[index].data!=key){
        index=(index+1)%size;
        if(index==hashing(key)){
            printf("\nNot found!");
            return;
        }
    }
    printf("\nFound!!");
}
void print(struct hash table[]){
    printf("\nHash Table:");
    for (int i=0;i<size;i++){
        printf("\n%d",table[i].data);
    }
}
int main(){
    int n,key;
    struct hash table[size];
    for (int i=0;i<size;i++){
        table[i].data=-1;
    }
    while(1){
        printf("\n1.Insert\n2.Find");
        printf("\nChoose the option :");
        scanf("%d",&n);
        if(n==1){
            printf("\nEnter the element :");
            scanf("%d",&key);
            insert(key,table);
            print(table);
        }
        else if(n==2){
            printf("\nEnter the element :");
            scanf("%d",&key);
            find(key,table);
            print(table);
        }
        else {
            break;
        }
    }
    return 0;
}
