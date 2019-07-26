/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    toh(3,'A','B','C');
    return 0;
}
void toh(int n,char src,char aux,char dest){
    if(n>=1){
        toh(n-1,src,dest,aux);
        printf("Move rod %d from %c to %c\n",n,src,dest);
        toh(n-1,aux,src,dest);
    }
}