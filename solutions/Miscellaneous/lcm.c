#include<stdio.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int num=1,ans = -1;
    if(a>=b){
        num=a;
    }
    else{
        num=b;
    }
    while(num <= (a*b)){
        if(num % a == 0 && num % b == 0 && ans == -1){
        ans=num;
        }
        num++;
    }
    printf("%d\n",ans);
    return 0;
}