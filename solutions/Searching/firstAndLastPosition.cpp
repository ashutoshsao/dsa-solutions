/*
 Problem: Find First and Last Position of Element in Sorted Array
 Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 Problem Statement: Given a sorted array of integers, the task is to find the starting and ending positions of a specific target value. The solution must be implemented with a logarithmic time complexity, O(log n). If the target is not present in the array, the function should return `[-1, -1]`.
 Approach: The solution utilizes two helper functions, `firstOccurrence` and `lastOccurrence`, to find the starting and ending indices of the target element. Both helper functions implement a modified binary search. `firstOccurrence` continues searching on the left side even after finding the target to ensure it's the first one. `lastOccurrence` searches on the right side to find the final one. The main function `searchRange` calls these two helpers and returns their results in a vector.
 Time Complexity: O(log n)
 Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int firstOccurrence(const vector<int> &nums, int k) {
    int low = 0, high = nums.size() - 1, ans = -1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] < k) {
        low = mid + 1;
      } else if (nums[mid] > k) {
        high = mid - 1;
      } else {
        ans = mid;
        high = mid - 1; // search on left side
      }
    }
    return ans;
  }

  int lastOccurrence(const vector<int> &nums, int k) {
    int low = 0, high = nums.size() - 1, ans = -1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] < k) {
        low = mid + 1;
      } else if (nums[mid] > k) {
        high = mid - 1;
      } else {
        ans = mid;
        low = mid + 1; // search on right side
      }
    }
    return ans;
  }

  vector<int> searchRange(vector<int> &nums, int target) {
    int first = firstOccurrence(nums, target);
    int last = lastOccurrence(nums, target);
    return {first, last};
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
    vector<int> ans = sol.searchRange(nums, k);
    cout << ans[0] << " " << ans[1] << "\n";
  }
  return 0;
}
