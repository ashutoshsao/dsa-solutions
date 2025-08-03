#include<stdio.h>
int main(){
    int n,i,j;
    scanf("%d",&n);
    int arr[n][n];
    for(i = 0;i < n;i++){
        for(j = 0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\n");

    for(i = 0;i < n;i++){
        for(j = 0;j<=i;j++){
        printf("%d",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i = 0;i < n;i++){
        for(int k=0;k<i;k++){
            printf(" ");
        }for(j = i;j<n;j++){
        printf("%d",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");


}
