/*
Problem: A. Wrong Subtraction
Link: https://codeforces.com/problemset/problem/977/A
Problem Statement: Little girl Tanya subtracts one from a number using a specific algorithm: if the last digit is non-zero, she decreases the number by one; if the last digit is zero, she divides the number by 10. Given an integer 'n' and a number of subtractions 'k', find the result after 'k' subtractions.
Approach: Simulate the process directly. Iterate 'k' times. In each iteration, check the last digit of 'n'. If it's non-zero, decrement 'n'. If it's zero, divide 'n' by 10.
Time Complexity: O(k) - The loop runs 'k' times, and each operation inside the loop is constant time.
Space Complexity: O(1) - Only a few variables are used to store 'n' and 'k'.
*/
#include<iostream>
using namespace std;
int main(){
    long n;
    int k;
    cin>>n>>k;
    for (int i = 0;i < k; i++){
        if(n%10==0){
            n=n/10;    
        }
        else {
            n-=1;
        }
    }
    cout<<n;
    return 0;
}