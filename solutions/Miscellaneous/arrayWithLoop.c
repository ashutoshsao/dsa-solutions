#include<stdio.h>
int main(){
    int marks[3];
    for(int i=0;i<3;i++){
        scanf("%d", &marks[i]);
    }
    for(int i=0;i<3;i++){
        printf("%d ",marks[i]);
    }
    printf("\n");
    return 0;
}