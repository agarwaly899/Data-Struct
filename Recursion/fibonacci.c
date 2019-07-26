#include<stdio.h>
 
long fibonnaci(int);
 
int main()
{
    int n,key;
    printf("Enter number of elements for fibonnaci:\n");
    scanf("%d", &n);
    printf("\n");
    for (int i=1;i<=n;i++){
        printf("%d ",fibonnaci(i));
    }
    return 0;
}
 
long fibonnaci(int n){
    int a;
    if ((n==1)||(n==2)){
        a=1;
        return a;
    }
    else if(n<=0){
        return 0;
    }
    else{
        a=fibonnaci(n-2)+fibonnaci(n-1);
        return a;
    }
}