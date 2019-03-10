/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
struct arraystack {
    int top1,top2;
    int capacity;
    int *array;
};
struct arraystack * createstack(int cap){
    struct arraystack * stack;
    stack=(struct arraystack *) malloc(sizeof(struct arraystack));
    stack->top1=-1;
    stack->capacity=cap;
    stack->top2=stack->capacity;
    stack->array=(int *) malloc(sizeof(int)*stack->capacity);
    return stack;
}
void push1(struct arraystack * stack){
    int item;
    printf("Eneter the data :");
    scanf("%d",&item);
    if(stack->top1<stack->top2-1){
        stack->top1++;
        stack->array[stack->top1]=item;
    }
    else {
        printf("stack overflow");
    }
}
void push2(struct arraystack * stack){
    int item;
    printf("Eneter the data :");
    scanf("%d",&item);
    if(stack->top1<stack->top2-1){
        stack->top2--;
        stack->array[stack->top2]=item;
    }
    else {
        printf("stack overflow");
    }
}
void pop1(struct arraystack * stack){
    if(stack->top1>=0){
        printf("\n%d ",stack->array[stack->top1]);
        stack->top1--;
    }
    else {
        printf("Stack underflow");
    }
}
void pop2(struct arraystack * stack){
    if(stack->top2<stack->capacity){
        printf("\n%d ",stack->array[stack->top2]);
        stack->top2++;
    }
    else {
        printf("Stack underflow");
    }
}
int main()
{   int a,cap;
    printf("Enter the total size of stack 1 and stack 2 :");
    scanf("%d",&cap);
    struct arraystack * Stack;
    Stack=createstack(cap);
    while(1){
        printf("\n1. push1\n2. push2\n3. pop1\n4. pop2\nEnter the option :");
        scanf("%d",&a);
        switch(a){
            case 1:push1(Stack);break;
            case 2:push2(Stack);break;
            case 3:pop1(Stack);break;
            case 4:pop2(Stack);break;
            default : exit(0);
        }
    }

    return 0;
}
