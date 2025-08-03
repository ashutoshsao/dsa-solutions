#include<stdio.h>
int main(){
    int x,N;
    double ans;
    scanf("%d %d",&N,&x);
    for(int i = 0;i <= N;i++){
        double num=1;
        for(int j = 1;j <= i;j++){
            num*=x;
        }
        double den=1;
        for(int j = 1;j <= i;j++){
            den*=j;
        }
        ans+=(num/den);
    }
    printf("%lf",ans);
    return 0;
}

// x^i/i!
// N=3,x=2
// 1+2+2^2/2!+2^3/3!
// 3+2+4/3
// 5+4/3
// (15+4)/3
// 19/3