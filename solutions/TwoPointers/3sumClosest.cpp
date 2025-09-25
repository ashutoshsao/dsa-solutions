/*
 Problem: 3Sum Closest
 Link: https://leetcode.com/problems/3sum-closest/
 Problem Statement: Given an integer array `nums` and an integer `target`, find three integers in `nums` whose sum is closest to `target`.
 Approach: The solution uses a two-pointer approach. First, the array is sorted. Then, for each element `nums[i]`, two pointers `p1` and `p2` are initialized to `i+1` and `n-1` respectively. The sum of `nums[i]`, `nums[p1]`, and `nums[p2]` is calculated. If the absolute difference between the sum and the target is less than the absolute difference between the current closest sum and the target, the closest sum is updated. If the sum is less than the target, `p1` is incremented. If the sum is greater than the target, `p2` is decremented. If the sum is equal to the target, the sum is returned.
 Time Complexity: O(n^2)
 Space Complexity: O(1)
*/
class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int closest = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n; i++) {
      int p1 = i + 1, p2 = n - 1;
      while (p1 < p2) {
        int sum = nums[i] + nums[p1] + nums[p2];
        if (abs(sum - target) < abs(closest - target)) {
          closest = sum;
        }

        if (sum < target)
          p1++;
        else if (sum > target)
          p2--;
        else
          return sum;
      }
    }
    return closest;
  }
};