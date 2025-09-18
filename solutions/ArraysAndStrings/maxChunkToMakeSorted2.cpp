/*
Problem: Max Chunks To Make Sorted
Link: https://leetcode.com/problems/max-chunks-to-make-sorted/
Problem Statement: You are given an integer array arr of length n that is a permutation of the integers in the range [0, n - 1].
We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should be the sorted array.
Return the largest number of chunks we can make to sort the array.
Approach: This solution uses an efficient approach to solve the problem in linear time. It iterates through the array while keeping track of the maximum element encountered so far. A chunk can be closed at index `i` if the maximum element in the subarray `arr[0...i]` is equal to `i`. This condition ensures that all elements smaller than or equal to `i` are contained within the current chunk, allowing it to be sorted independently to form a valid segment of the final sorted array.
Time Complexity: O(n), as it involves a single pass through the array.
Space Complexity: O(1), as it uses only a few variables to keep track of the maximum element and the chunk count.
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int maxm = INT_MIN, cnt = 0;
  for (int i = 0; i < n; i++) {
    maxm = max(maxm, v[i]);
    if (maxm == i) {
      cnt++;
    }
  }
  cout << cnt << "\n";
}