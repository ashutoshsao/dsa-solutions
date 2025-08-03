#include<stdio.h>
int main(){
    char word1[100];
    char word2[100];
    int i;
    scanf("%s %s",word1,word2);
    for(i=0;word1[i] != '\0' && word2[i] != '\0';i++){
        if(word1[i] != word2[i])
            break;
    }
    if(word1[i] == '\0' && word2[i] == '\0')
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
