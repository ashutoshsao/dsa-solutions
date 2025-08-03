#include<stdio.h>
#include<limits.h>
int main(){
    int i,j;
    char word[100]="ashutoshsao";
    for(i=0;word[i] != '\0';i++){
        int min=INT_MAX,indx;
        for(j=i;word[j] != '\0';j++){
            if(word[j] < min){
                min = word[j];
                indx = j;
            }
        }
        char temp = word[i];
        word[i] = word[indx];
        word[indx] = temp;
    }
    printf("%s\n",word);
}
