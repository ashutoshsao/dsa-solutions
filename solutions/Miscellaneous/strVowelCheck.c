#include<stdio.h>
int main(){
    char word[100] = "ashutosh sao";
    char vowels[11] = "aeiouAEIOU";
    int len = 0,chr=0,i=0,j=0;
    while(word[i] != '\0'){
        i++;
        len++;
    }
    for(i=0;i<len;i++){
        for(j=0;j<10;j++){
            if(word[i]==vowels[j]){
                chr++;
                break;
            }
        }
    }
    printf("%d\n",chr);
}
