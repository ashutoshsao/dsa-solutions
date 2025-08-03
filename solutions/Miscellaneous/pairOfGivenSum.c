#include<stdio.h>
int main(){
    int N,i,j,x;
    scanf("%d",&N);
    int arr[N];
    for(i=0;i<N;i++)
        scanf("%d",&arr[i]);
    scanf("%d",&x);
    for(i=0;i<N;i++){
        for(j=i+1;j<N;j++){
            if(arr[i]+arr[j]==x){
                printf("%d + %d = %d\n",arr[i],arr[j],x);
            }
        }
    }
    return 0;
}
