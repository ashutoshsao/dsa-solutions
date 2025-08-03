#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    double sum = 0;
    for(double i = 1;i <= N;i++){
        sum+=1/i;
    }
    printf("%lf",sum);
    return 0;
}