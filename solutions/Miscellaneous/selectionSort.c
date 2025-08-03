#include <limits.h>
#include<stdio.h>
int main(){
    int N,i,j;
    scanf("%d",&N);
    int arr[N];
    for(i=0;i<N;i++)
        scanf("%d",&arr[i]);
    for (i = 0;i<N;i++){
        int min = INT_MAX,idx;
        for (j = i;j<N;j++){
            if(arr[j] < min){
                min = arr[j];
                idx = j;
                }
            }
        int temp = arr[i];
        arr[i]= arr[idx];
        arr[idx]= temp;
    }
    for(i=0;i<N;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
