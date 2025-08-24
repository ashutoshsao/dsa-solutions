/*
Problem: 719. Find K-th Smallest Pair Distance
Link: https://leetcode.com/problems/find-k-th-smallest-pair-distance/
Problem Statement: Given an integer array, find the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.
Approach: The solution uses binary search on the answer. The range of possible distances is from 0 to the difference between the maximum and minimum elements in the array. For a given distance `mid`, we count the number of pairs with a distance less than or equal to `mid`. If the count is less than `k`, we need a larger distance, so we search in the range `[mid + 1, right]`. Otherwise, we search in the range `[left, mid]`.
Time Complexity: O(N log N + N log W), where N is the number of elements in the array and W is the difference between the maximum and minimum elements. O(N log N) for sorting and O(N log W) for the binary search with the two-pointer approach for counting pairs.
Space Complexity: O(1) (excluding the space for the input array).
*/

#include <bits/stdc++.h>
using namespace std;

// For each right position, find how far left we can go
int countPairs(vector<int> &nums, int target) {
  int count = 0;
  int left = 0;

  for (int right = 1; right < nums.size(); right++) {
    // Move left pointer until distance <= target
    while (nums[right] - nums[left] > target) {
      left++;
    }
    count += right - left;
  }

  return count;
}

int main() {
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int k;
  cin >> k;

  sort(nums.begin(), nums.end());

  int left = 0;
  int right = nums[n - 1] - nums[0];

  while (left < right) {
    int mid = left + (right - left) / 2;
    int pairCount = countPairs(nums, mid);

    if (pairCount < k) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  cout << left << endl;

  return 0;
}
