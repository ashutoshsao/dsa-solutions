#include<stdio.h>
int main(){
    char s1[100] = "i am a good programmer";
    char s2[100];
    int i;
    for(i=0;s1[i] != '\0';i++){
        s2[i] = s1[i];
    }
    s2[i]='\0';
    printf("%s\n",s2);
}
