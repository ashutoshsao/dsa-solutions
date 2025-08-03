#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    int a[N];
    int K;
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        scanf("%d", &a[i]);
    }
    for(int i=0;i<K;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    int x,index;
    scanf("%d %d",&x,&index);
    for(int i=(K-1);i>=index;i--){
        a[i+1]=a[i];
    }
    a[index]=x;
    for(int i=0;i<K+1;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}