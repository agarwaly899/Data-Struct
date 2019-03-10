/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
struct arraystack{
    int top;
    int capacity;
    char * array;
};
struct arraystack * createStack(int cap){
    struct arraystack * stack;
    stack=(struct arraystack *) malloc(sizeof(struct arraystack));
    stack->top=-1;
    stack->capacity=cap;
    stack->array=(char *) malloc(sizeof(char)*(stack->capacity));
    return stack;
}
int isFull(struct arraystack * stack){
    return (stack->top==stack->capacity-1);
}
int isEmpty(struct arraystack * stack){
    return (stack->top==-1);
}
void push(struct arraystack * stack,char item){
    if(!isFull(stack)){
        stack->top++;
        stack->array[stack->top]=item;
    }
}
char pop(struct arraystack * stack){
    char item;
    if(!isEmpty(stack)){
        item=stack->array[stack->top];
        stack->top--;
        return item;
    }
    return NULL;
}
void reverse(struct arraystack * stack,char str[],int cap){
    for(int i=0;i<cap;i++){
    push(stack,str[i]);
    }
    for(int i=0;i<cap;i++){
    printf("%c ",pop(stack));
    }
}
int main(){
    char str[]="yashuu";
    struct arraystack * stack=createStack(6);
    reverse(stack,str,6);
    return 0;
}
