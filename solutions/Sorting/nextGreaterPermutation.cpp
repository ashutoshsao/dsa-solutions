/*
Problem: Next Greater Permutation
Link: https://leetcode.com/problems/next-permutation/
Problem Statement: Implement the next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
Approach: The solution finds the first decreasing element from the right, swaps it with the smallest element to its right that is larger than it, and then reverses the suffix starting from the pivot position.
Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    // Step 1: Find the pivot (x)
    int x = n - 1;
    while (x > 0 && nums[x - 1] >= nums[x])
      x--;

    // Step 2: Swap pivot with first element greater than it (y)
    if (x > 0) {
      for (int y = n - 1; y >= x; y--) {
        if (nums[y] > nums[x - 1]) {
          swap(nums[y], nums[x - 1]);
          break;
        }
      }
    }

    // Step 3: Reverse the suffix (i = x, j = n-1)
    int i = x, j = n - 1;
    while (i < j) {
      swap(nums[i], nums[j]);
      i++;
      j--;
    }

    // Output
    for (int num : nums)
      cout << num << " ";
    cout << "\n";
  }
  return 0;
}
