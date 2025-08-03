#include<stdio.h>
int main(){
    int prev=0 ,next=5 ,N ,temp ;
    scanf("%d",&N);
    if(N==1){
        printf("0");
    }
    else{
        printf("%d %d ",prev,next);
        int i=3;
        while(i<=N){
            temp=prev+next;
            printf("%d ",temp);
            prev=next;
            next=temp;
            i++;
        }
    }
    printf("\n");
    return 0;
}