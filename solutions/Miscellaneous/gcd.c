//gcd of two numbers
#include<stdio.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int i=1,gcd=1;
    while(i<=a){
        if(a%i==0 && b%i==0){
            gcd=i;
        }
        i++;
    }
    printf("%d\n",gcd);
    return 0;
}