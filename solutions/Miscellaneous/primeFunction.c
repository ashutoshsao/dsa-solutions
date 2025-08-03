#include<stdio.h>
int isprime(int a){
    int count = 0,i;
    for(int i = 1;i<=a;i++){
        if(a % i == 0){
            count++;
        }
    }
    return((count==2)?1:0);
}
int main(){
    int a = 5;
    int result = isprime(a);
    printf("%s",(result)?"yes":"no");
}
