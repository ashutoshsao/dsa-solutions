/*
 Problem: Binary Search
 Link: https://leetcode.com/problems/binary-search/description/
 Problem Statement: Given a sorted array of integers `nums` and an integer `target`, write a function to search for the `target` within `nums`. If the `target` value exists in the array, the function should return its index. If the `target` is not found, the function must return -1. The algorithm must have a runtime complexity of O(log n).
 Approach: The solution uses an iterative binary search approach. It initializes `low` and `high` pointers to the start and end of the array. In each iteration, it calculates the middle index `m`. If the middle element is the target, it returns the index. If the middle element is less than the target, it moves the `low` pointer to `m + 1`. Otherwise, it moves the `high` pointer to `m - 1`. If the loop finishes without finding the target, it returns -1.
 Time Complexity: O(log n)
 Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int k) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
      int m = low + (high - low) / 2;
      if (nums[m] == k) {
        return m;
      } else if (nums[m] < k) {
        low = m + 1;
      } else {
        high = m - 1;
      }
    }
    return -1;
  }
};

int main() {
  int n;
  cin >> n; // read size of array
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int t;
  cin >> t; // number of queries
  Solution sol;

  while (t--) {
    int k;
    cin >> k;
    cout << sol.search(nums, k) << "\n";
  }

  return 0;
}
