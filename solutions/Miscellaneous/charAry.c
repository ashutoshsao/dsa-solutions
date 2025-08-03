#include<stdio.h>
int main(){
    char word[7];
    int i;
    for(i=0;i<7;i++){
        scanf("%c",&word[i]);
    }
    for(i=0;i<7;i++){
        printf("%c",word[i]);
    }
    printf("\n");
}
