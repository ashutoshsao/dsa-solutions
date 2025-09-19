/*
Problem: Rearrange Array
Link: Not available from a standard platform.
Problem Statement: Given an array `arr` of size `n` where elements are in the range `[0, n-1]`. The task is to rearrange the array such that if `arr[i] = j`, then `arr[j]` becomes `i`.
Approach: The solution uses a clever in-place approach to rearrange the array without using any extra space. It uses the array elements themselves to store two values. The idea is to store the new value and the old value in the same location.
The new value `i` is encoded into `arr[j]` by adding `i*n` to it.
The original value at `arr[j]` can be retrieved by taking the modulo with `n`.
The new value can be retrieved by dividing by `n`.
The algorithm iterates through the array, and for each element `arr[i]`, it updates the element at index `arr[i]` to store `i`.
After updating all the elements, it iterates through the array again and divides each element by `n` to get the new values.
Time Complexity: O(n), as it involves two passes through the array.
Space Complexity: O(1), as it modifies the array in-place.
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  for (int i = 0; i < n; i++) {
    int old_val = v[i] % n;
    v[old_val] = ((long long)n * i) + v[old_val];
  }

  for (int i = 0; i < n; i++) {
    v[i] = v[i] / n;
  }

  for (int i = 0; i < n; i++) {
    cout << v[i] << " ";
  }
  cout << '\n';
}