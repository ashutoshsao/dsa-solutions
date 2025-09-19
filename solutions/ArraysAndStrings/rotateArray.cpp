/*
Problem: Rotate Array
Link: https://leetcode.com/problems/rotate-array/
Problem Statement: Given an array, rotate the array to the right by k steps, where k is non-negative.
Approach: The solution uses the reversal algorithm to rotate the array in-place. The algorithm consists of three steps:
1. Reverse the first `n-k` elements of the array.
2. Reverse the last `k` elements of the array.
3. Reverse the entire array.
This sequence of reversals results in the array being rotated to the right by `k` steps.
Time Complexity: O(n), as it involves a constant number of passes through the array.
Space Complexity: O(1), as the rotation is done in-place.
*/
#include <bits/stdc++.h>
using namespace std;
#include <climits>
int main() {
  int n, k;
  cin >> n >> k;
  int z = k % n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  if (n > 1) {
    reverse(v.begin(), (v.end() - z));
    reverse(v.end() - z, v.end());
    reverse(v.begin(), v.end());
  }
  for (int i = 0; i < n; i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}