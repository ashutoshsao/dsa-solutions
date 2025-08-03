#include<stdio.h>
int main(){
    int N,i,j,len=0;
    scanf("%d",&N);
    char word[N][100];
    for(i = 0;i<N;i++){
        scanf("%s",word[i]);
    }
    for(i = 0;i<N;i++){
        len = 0;
        for(j=0;word[i][j] != '\0';j++){
            len++;
        }
        printf("%d\n",len);
    }
    return 0;
}
