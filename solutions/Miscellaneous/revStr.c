#include<stdio.h>
int main(){
    char word[100]= "this is awesome!!!";
    int len = 0, i=0;
    while(word[i] != '\0'){
        i++;
        len++;
    }
    for(i = len - 1;i > -1; i--){
        printf("%c",word[i]);
    }
    printf("\n");
    return 0;
}
