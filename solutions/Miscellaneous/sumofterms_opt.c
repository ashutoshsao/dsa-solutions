#include<stdio.h>
int main(){
    int x,N;
    double ans=0,num=1,den=1;
    scanf("%d %d",&N,&x);
    for(int i = 0;i <= N;i++){
        ans+=(num/den);
        num*=x;
        den*=(i+1);
    }
    printf("%lf",ans);
    return 0;
}