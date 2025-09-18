/*
Problem: Max Chunks To Make Sorted
Link: https://leetcode.com/problems/max-chunks-to-make-sorted/
Problem Statement: You are given an integer array arr of length n that is a permutation of the integers in the range [0, n - 1].
We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should be the sorted array.
Return the largest number of chunks we can make to sort the array.
Approach: The provided solution uses a brute-force approach. It iterates through all possible chunk boundaries. For each potential chunk from index `i` to `j`, it checks if the subarray `arr[i...j]` contains all the numbers from `i` to `j`. If it does, a valid chunk is found, and the process continues from the next index. The `canBeChunked` function verifies this condition by counting how many elements within the subarray fall into the desired range of values.
Time Complexity: O(n^3), where n is the size of the array. The nested loops and the `canBeChunked` function lead to a cubic time complexity.
Space Complexity: O(1), as no extra space is used besides the input vector.
*/
#include <bits/stdc++.h>
#include <ostream>
#include <vector>
using namespace std;
bool canBeChunked(int i, int j, vector<int> &v) {
  int cnt = 0;
  for (int k = i; k <= j; k++) {
    if (v[k] >= i && v[k] <= j) {
      cnt++;
    }
  }
  if (cnt == j - i + 1)
    return true;
  else
    return false;
}
int main() {
  int n, i, j, ans = 0;
  cin >> n;
  vector<int> v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }
  i = 0;
  while (i < n) {
    for (j = i; j < n; j++) {
      if (canBeChunked(i, j, v))
        break;
    }
    i = j + 1;
    ans++;
  }
  cout << ans << "\n";
}