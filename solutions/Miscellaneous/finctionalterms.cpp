#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    double sum = 0;
    for(double i = 1;i <= N;i++){
        sum+=1/i;
    }
    cout<<sum;
    return 0;
}