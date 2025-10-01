/*
 * Problem: Ugly Number II
 * Link: https://leetcode.com/problems/ugly-number-ii/
 * Problem Statement: An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5. Given an integer n, return the nth ugly number.
 * Approach: The solution uses a dynamic programming approach with three pointers. We build an array of ugly numbers. The next ugly number is the minimum of the next multiple of 2, 3, and 5 from the previously found ugly numbers. We use three pointers, `p1`, `p2`, and `p3`, to keep track of the indices of the ugly numbers to be multiplied by 2, 3, and 5, respectively.
 * Time Complexity: O(n), as we iterate n times to find the nth ugly number.
 * Space Complexity: O(n), for storing the ugly numbers in a vector.
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int nthUglyNumber(int n) {
    int p1 = 0, p2 = 0, p3 = 0, n1 = 2, n2 = 3, n3 = 5;
    vector<int> nums(n);
    nums[0] = 1;
    for (int i = 1; i < n; i++) {
      int val = min(nums[p1] * n1, min(nums[p2] * n2, nums[p3] * n3));
      nums[i] = val;
      if (val == nums[p1] * n1)
        p1++;
      if (val == nums[p2] * n2)
        p2++;
      if (val == nums[p3] * n3)
        p3++;
    }
    return nums[n - 1];
  }
};

int main() {
  int n;
  cin >> n;
  int ans = nthUglyNumber(n);
  cout << ans << "\n";
  return 0;
}
