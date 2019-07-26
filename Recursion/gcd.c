#include<stdio.h>
 
void gcd(int,int);
 
int main()
{
    int a,b;
    printf("Enter two no.s to calculate gcd:\n");
    scanf("%d %d",&a,&b);
    while((a<0)||(b<0)){
        printf("Entered no.s should be positive:\n");
        scanf("%d %d",&a,&b);
    }
    gcd(a,b); 
    return 0;
}
void gcd(int a,int b){
    if((a<b)&&(a!=0)){
        gcd(a,b%a);
    }
    else if((b<a)&&(b!=0)){
        gcd(a%b,b);
    }
    else {
        if(b!=0){
            printf("\nThe gcd is : %d",b);
        }
        else if(a!=0){
            printf("\nThe gcd is : %d",a);
        }
    }
}