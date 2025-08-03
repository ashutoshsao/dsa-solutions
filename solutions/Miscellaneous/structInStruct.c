#include<stdio.h>
struct Subjects{
    int totalsub;
};
struct Education {
    char degree[10];
    int gradYear;
    char college[50];
    struct Subjects sub;
};
struct Person {
    char name[50];
    int age;
    char gender;
    struct Education edu;
};
int main(){
    struct Subjects s = {12};
    struct Education e = {"B.Tech",2025,"MIT",s};
    struct Person p = {"ram",24,'m',e};
    printf("%s %d %s\n",p.edu.degree,p.edu.sub.totalsub,p.edu.college);
    return 0;
}
