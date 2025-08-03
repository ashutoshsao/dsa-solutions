// program to store marks of 3 students
#include<stdio.h>
int main(){
    int marks[3];
    scanf("%d", &marks[0]);
    scanf("%d", &marks[1]);
    scanf("%d", &marks[2]);
    float x = (marks[0] + marks[1] + marks[2])/3.0;
    printf("%f\n",x);
    return 0;
}