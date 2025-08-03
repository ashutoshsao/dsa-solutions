#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    //count the total power
    int temp=N,p=1;
    while(temp){
        temp /= 10;
        p*=10;
    }
    p/=10;
    int ans=0;
    while(N){
        int r = N % 10;
        ans += r * p;
        p /= 10;
        N /= 10;
    }
    printf("%d\n",ans);
    return 0;
}
// 345      3   5*100
// 45  1    2   4*10
// 4   2    1   4*1
// 0   3