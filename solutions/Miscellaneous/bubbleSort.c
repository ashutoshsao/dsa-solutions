#include <stdio.h>
int main(){
    int N,i,j;
    scanf("%d",&N);
    int arr[N];
    for(i=0;i<N;i++)
        scanf("%d",&arr[i]);
    for (i = 0;i<N-1;i++){
        for(j=0;j<N-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    for(int k=0;k<N;k++)
        printf("%d ",arr[k]);
    printf("\n");
    }
    for(i=0;i<N;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
