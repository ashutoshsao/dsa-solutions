#include<stdio.h>
#include <string.h>
int main(){
    char s1[100] = "i love to code";
    char s2[100] ="in c"; 
    strcat(s1,s2);
    printf("%s\n",s1);
}
