#include<stdio.h>
struct A {
    int m;
    float n;
};
int main(){
    struct A a = {4,5.6};
    struct A * ptr = &a;
    printf("%d %f\n",ptr->m,ptr->n);
    printf("%d %f\n",(*ptr).m,(*ptr).n);
    return 0;
}
