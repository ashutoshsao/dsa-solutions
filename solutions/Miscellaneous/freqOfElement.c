#include<stdio.h>
int main(){
    int N,i;
    scanf("%d",&N);
    int arr[N];
    for(i=0;i<N;i++)
        scanf("%d",&arr[i]);
    int x,count=0;
    scanf("%d",&x);
    for(i=0;i<N;i++){
        if(arr[i]==x)
            count++;
    }
    printf("%d\n",count);
    return 0;
}