#include <stdio.h>
int main(){
    int N,i,j;
    scanf("%d",&N);
    int arr[N];
    for(i=0;i < N;i++){
        scanf("%d",&arr[i]);
    }
    for (i = 1;i < N;i++){
        j=i;
        while(j > 0 && arr[j] < arr[j-1] ) {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }    
    }
    for(i = 0;i < N;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}