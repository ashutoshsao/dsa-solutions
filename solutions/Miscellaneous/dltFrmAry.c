#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    int k;
    scanf("%d",&k);
    int a[k],i;
    for(i=0;i<k;i++)
        scanf("%d",&a[i]);
    int index;
    scanf("%d",&index);
    for (i = index+1; i < k; i++)
        a[i-1]=a[i];
    for(i=0;i<k-1;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}