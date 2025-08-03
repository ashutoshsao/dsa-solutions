#include<stdio.h>
int main(){
    int N,i;
    scanf("%d",&N);
    int arr[N];
    for(i=0;i<N;i++)
        scanf("%d",&arr[i]);
    for(int j=0;j<N;j++){
        int x = arr[j];  
        int count=0; 
        for(i=0;i<N;i++){
            if(arr[i]==x)
            count++;
        }
    printf("frequency of %d = %d\n",x,count);
    }      
    return 0;
}