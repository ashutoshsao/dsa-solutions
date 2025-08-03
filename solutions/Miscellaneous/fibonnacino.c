// prints the nth index fabonacci no.
#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    if(N==0){
        printf("0");
    }
    else{
        int x=0,y=1;
        for(int i=2;i<=N;i++){
            int temp=x+y;
            x=y;
            y=temp;
        }
        printf("%d ",y);
    }
    printf("\n");
    return 0;
}