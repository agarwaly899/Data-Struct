/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
struct queue {
    int front ,rear;
    int capacity;
    char *array;
};
struct queue * createQueue(int cap){
    struct queue * Q;
    Q=(struct queue *) malloc(sizeof(struct queue));
    Q->capacity=cap;
    Q->front=Q->rear=-1;
    Q->array=(char *)malloc(sizeof(char)*Q->capacity);
    return Q;
}
int isFull(struct queue * Q){
    return ((Q->rear+1)%Q->capacity==Q->front);
}
int isEmpty(struct queue * Q){
    return (Q->front==-1);
}
void enqueue(struct queue * Q){
    char item;
    if(isFull(Q)){
        printf("Queue is full\n");
        return;
    }
    if(!isFull(Q)){
        printf("Enter the character :");
        scanf(" %c",&item);
        Q->rear=(Q->rear+1)%Q->capacity;
        Q->array[Q->rear]=item;
        if(Q->front==-1){
            Q->front=Q->rear;
        }
    }
}
void dequeue(struct queue * Q){
    int data;
    if(!isEmpty(Q)){
        data=Q->array[Q->front];
        Q->array[Q->front]=NULL;
        if(Q->front==Q->rear) {
            Q->front=Q->rear=-1;
        }   
    else{
            Q->front=(Q->front+1)%Q->capacity;
        }
    }
    printf("\n%c is deleted\n",data);
}
void print(struct queue * Q){
    for (int i=0;i<5;i++){
        printf("%c",Q->array[i]);
    }
}
int main()
{   
    struct queue * Q;
    Q=createQueue(5);
    int a;
    while(1){
        printf("Enter the option :");
        scanf("%d",&a);
        switch(a){
            case 1:enqueue(Q);break;
            case 2:dequeue(Q);break;
            case 3:print(Q);break;
            default:exit(0);
        }
    }
}
