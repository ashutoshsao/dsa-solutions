/*
Problem: Presents
Link: https://codeforces.com/problemset/problem/136/A
Problem Statement: Little Petya gave his friends gifts for the New Year. He knows that the friend with number `i` gave a gift to the friend with number `p_i`. He wants to know who gave a gift to whom.
Approach: The solution uses an array to solve the problem. It iterates through the input array, which tells us who gave a gift to whom. For each friend `i` who gave a gift to friend `p_i`, we can deduce that friend `p_i` received a gift from friend `i`. The solution uses an answer array to store this information, where `ans[p_i] = i`.
Time Complexity: O(n), as it involves a few passes through the array.
Space Complexity: O(n), for the answer array.
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> arr(n+1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    vector <int> ans(n+1);
    for(int i = 1; i <= n; i++){
        ans[arr[i]]=i;
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}