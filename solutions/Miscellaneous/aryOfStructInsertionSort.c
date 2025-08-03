#include <limits.h>
#include<stdio.h>
struct person{
    char name[20];
    int age;
    char gender;
};
int main(){
    int n;
    scanf("%d",&n);
    struct person persons[n];
    for(int i = 0; i < n; i++){
        scanf("%s %d %c", persons[i].name, &persons[i].age, &persons[i].gender);
    }
    for (int i = 1; i < n; i++) {
        int j =i;
        while(j>0 && persons[j].age<persons[j-1].age){
            struct person temp = persons[j];
            persons[j]=persons[j-1];
            persons[j-1]=temp;
            j--;
        }
    }
    for(int i = 0; i < n; i++){
        printf("%s %d %c\n", persons[i].name, persons[i].age, persons[i].gender);
    }  
    return 0;
}

