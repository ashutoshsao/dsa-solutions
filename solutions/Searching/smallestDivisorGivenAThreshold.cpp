/*
Problem: Find the Smallest Divisor Given a Threshold
Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
Problem Statement: Given an array of integers nums and an integer threshold, we will choose a positive integer divisor and divide all the array elements by it and sum the result of the division. Find the smallest divisor such that the result mentioned above is less than or equal to threshold. Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3, 10/2 = 5).
Approach: The code uses binary search on the answer. The search space for the divisor is from 1 to the maximum element in the array. For a given divisor `m`, the function `Satisfies` calculates the sum of `ceil(nums[i] / m)` for all `i`. If the sum is less than or equal to the threshold `k`, it means `m` could be a possible answer, so we try to find a smaller divisor by setting `h = m - 1`. Otherwise, we need a larger divisor, so we set `l = m + 1`.
Time Complexity: O(n * log(max(nums)))
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

bool Satisfies(int m, vector<int> &nums, int k) {
  int n = nums.size(), sum = 0;
  for (int i = 0; i < n; i++) {
    sum += (nums[i] + m - 1) / m;
  }
  return sum <= k;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  int maxN;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    maxN = max(nums[i], maxN);
  }
  int k;
  cin >> k;
  int l = 1, h = maxN, ans = -1;
  while (l <= h) {
    int m = l + (h - l) / 2;
    bool r = Satisfies(m, nums, k);
    if (!r)
      l = m + 1;
    else {
      ans = m;
      h = m - 1;
    }
  }
  cout << ans << "\n";
}
