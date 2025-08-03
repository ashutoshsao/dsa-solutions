#include<stdio.h>
int main(){
    int a[] = {1,5,4,3,2};
    int b[5];
    for(int i=0;i<5;i++){
        b[i] = a[i];
        printf("%d ",b[i]);
    }
    printf("\n");
    return 0;
}