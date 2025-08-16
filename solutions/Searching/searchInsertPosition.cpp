/*
 Problem: Search Insert Position
 Link: https://leetcode.com/problems/search-insert-position/description/
 Problem Statement: Given a sorted array of distinct integers and a target value, the goal is to find the index of the target if it exists in the array. If the target is not found, the function should return the index where the target would be inserted to maintain the sorted order. This must be achieved with an algorithm that has a logarithmic time complexity, O(log n).
 Approach: The solution uses binary search to find the target value. If the target is found, its index is returned. If the loop finishes without finding the target, the `low` pointer will be at the correct insertion position. This is because the loop terminates when `low > high`, and `low` represents the first element greater than the target, which is the insertion point.
 Time Complexity: O(log n)
 Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int k) {
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

    return low;
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int t;
  cin >> t;
  Solution sol;

  while (t--) {
    int k;
    cin >> k;
    cout << sol.searchInsert(nums, k) << "\n";
  }

  return 0;
}
