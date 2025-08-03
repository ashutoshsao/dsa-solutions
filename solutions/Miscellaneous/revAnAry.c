#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    int a[N];
    for(int i=0;i<N;i++){
        scanf("%d", &a[i]);
    }
    int temp=0;
    for(int i=0;i<=N/2;i++){
        temp=a[N-(i+1)];
        a[N-(i+1)]=a[i];
        a[i]=temp;
    }
    for(int i=0;i<N;i++){
        printf("%d ",a[i]);
    }  
    printf("\n");
    return 0;
}