/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
void insertion(int A[],int n){
    int i,j,temp;
    for(i=1;i<n;i++){
        temp=A[i];
        for(j=i-1;(j>=0)&&(temp<A[j]);j--){
            A[j+1]=A[j];
        }
        A[j+1]=temp;
    }
    printf("\nSorted Array : ");
    for(int k=0;k<n;k++){
        printf("%d ",A[k]);
    }
}
int main()
{   int n=7;
    int A[]={7,8,9,3,4,5,1};
    printf("\nOriginal Array : ");
    for(int k=0;k<n;k++){
        printf("%d ",A[k]);
    }
    insertion(A,n);
    return 0;
}
