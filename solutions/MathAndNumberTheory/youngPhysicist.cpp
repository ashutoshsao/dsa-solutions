/*
Problem: Young Physicist (Codeforces 69A)
Link: https://codeforces.com/problemset/problem/69/A
Problem Statement: A body is in equilibrium if the sum of all forces acting on it is zero. You are given 'n' forces, each represented by three integer coordinates (x, y, z). Your task is to determine if the body is in equilibrium.

Approach: To determine if the body is in equilibrium, we need to check if the net force along each of the three axes (x, y, and z) is zero. We can achieve this by initializing three separate sum variables (one for each axis) to zero. Then, for each of the 'n' forces, we read its x, y, and z components and add them to their respective sum variables. After processing all 'n' forces, if all three sum variables are zero, the body is in equilibrium, and we print "YES". Otherwise, if at least one of the sums is not zero, the body is not in equilibrium, and we print "NO".

Time Complexity: O(n), where 'n' is the number of forces. This is because we iterate through the 'n' forces once to sum their components.
Space Complexity: O(1), as we only use a constant amount of extra space for the sum variables, regardless of the number of forces.
*/
#include<iostream>
using namespace std;
int main(){
    int n,x,y,z,sumx,sumy,sumz;
    sumx=sumy=sumz=0;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>x>>y>>z;
        sumx+=x;
        sumy+=y;
        sumz+=z;
    }
    if(sumx==0 && sumy==0 && sumz==0)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}