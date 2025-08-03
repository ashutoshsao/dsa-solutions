#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    long long sum=0,t=1,i;
    for(i=1;i<=N;i++){
        sum+=t;
        printf("%lld ",t);
        t=t * 10 + 1;
    }
    printf("\n%lld\n",sum);
    return 0;
}