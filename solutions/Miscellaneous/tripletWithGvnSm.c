#include<stdio.h>
int main(){
    int N,i,j,k,x;
    scanf("%d",&N);
    int arr[N];
    for(i=0;i<N;i++)
        scanf("%d",&arr[i]);
    scanf("%d",&x);
    for(i=0;i<N;i++){
        for(j=i+1;j<N;j++){
            for(k=j+1;k<N;k++){
                if(arr[i]+arr[j]+arr[k]==x){
                    printf("%d + %d + %d= %d\n",arr[i],arr[j],arr[k],x);
                }
            }
        }
    }
    return 0;
}
