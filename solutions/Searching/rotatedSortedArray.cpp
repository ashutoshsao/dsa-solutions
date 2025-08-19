/*
Problem: Search in Rotated Sorted Array
Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
Problem Statement: Given a sorted array of distinct integers that has been rotated at an unknown pivot, find the index of a target value. If the target is not found, return -1. The algorithm must have a time complexity of O(log n).
Approach: The solution uses a modified binary search. In each iteration, it determines which half of the array (left or right of the midpoint) is sorted. If the target falls within the range of the sorted half, the search is narrowed to that half. Otherwise, the search continues in the other half.
Time Complexity: O(log n)
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target) {
  int left = 0, right = nums.size() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (nums[mid] == target) {
      return mid;
    }

    // Check if left half is sorted
    if (nums[left] <= nums[mid]) {
      // Target is in the left sorted half
      if (target >= nums[left] && target < nums[mid]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    // Right half is sorted
    else {
      // Target is in the right sorted half
      if (target > nums[mid] && target <= nums[right]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }

  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int t;
  cin >> t;
  while (t--) {
    int target;
    cin >> target;
    cout << search(nums, target) << "\n";
  }

  return 0;
}
