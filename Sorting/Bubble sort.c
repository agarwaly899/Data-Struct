/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
void Sink(int A[],int n){
    int round,j,temp,flag;
    for(round=0;round<n;round++){
        flag=0;
        for(j=0;j<n-round-1;j++){
            if(A[j]>A[j+1]){
                flag=1;
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
        if(flag==0){
            printf("\nSorted Array : ");
            for(int k=0;k<n;k++){
                printf("%d ",A[k]);
            }
            return;
        }
    }
}
int main()
{   int n=7;
    int A[]={7,8,9,3,4,5,1};
    printf("\nOriginal Array : ");
    for(int k=0;k<n;k++){
        printf("%d ",A[k]);
    }
    Sink(A,n);
    return 0;
}
