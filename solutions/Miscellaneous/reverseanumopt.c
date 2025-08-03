#include<stdio.h>
int main(){
    int N,r=0;
    scanf("%d",&N);
    int ans=0;
    while(N){
        r = N % 10;
        ans = ans * 10 + r;
        N /= 10;
    }
    printf("%d\n",ans);
    return 0;
}

// 234
// 4
// 40
// 43