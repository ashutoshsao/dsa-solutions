#include <stdio.h>
int main(void) {
    int n,m,i,j,sum=0;
    scanf("%d %d",&n,&m);
    int arr[n][m];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<n;i++){
        sum+=arr[i][i];
    }
    j=m-1;
    for(i=0;i<n;i++){
            sum+=arr[i][j];
            j--;
    }
    if(n%2!=0 && m/2!=0){
        sum-=arr[n/2][m/2];
    }
    printf("%d\n",sum);
    return 0;
}
