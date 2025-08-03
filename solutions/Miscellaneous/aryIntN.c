#include<stdio.h>
int main(){
    int N,sum=0;
    scanf("%d",&N);
    int marks[N];
    for(int i=0;i<N;i++){
        scanf("%d", &marks[i]);
        sum += marks[i];
    }
    printf("%d\n",sum);
    return 0;
}