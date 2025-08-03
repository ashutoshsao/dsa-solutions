#include<stdio.h>
int main(){
    int n,i,j;
    scanf("%d",&n);
    int arr[n][n],sum=0;
    for(i = 0;i < n;i++){
        for(j = 0;j < n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    i = 0,j=n-1;
    while(i<n){
        sum+=arr[i][j];
        i++;
        j--;
    }
    i = 0,j=0;
    while(i<n){
        sum+=arr[i][j];
        i++;
        j++;
    }
    if(n%2!=0)
       sum -= arr[n/2][n/2];
    for(i = 0;i < n;i++){
        for(j = 0;j < n;j++){
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
    printf("%d\n",sum);

    
    return 0;
}

