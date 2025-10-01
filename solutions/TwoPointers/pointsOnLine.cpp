/*
 * Problem: Points on Line
 * Link: https://codeforces.com/contest/252/problem/C
 * Problem Statement: Given n points on a line, find the number of ways to choose three distinct points such that the distance between the two outermost points is at most d.
 * Approach: The solution uses a two-pointer approach. It iterates through the points with a right pointer `j` and maintains a left pointer `i` such that `nums[j] - nums[i] <= d`. For each `j`, the number of valid points between `i` and `j` (exclusive of `j`) is `len = j - i`. The number of pairs of points that can be chosen from this range is `len * (len - 1) / 2`. This is added to the total count.
 * Time Complexity: O(n), where n is the number of points, because each pointer traverses the array once.
 * Space Complexity: O(1) auxiliary space, as the solution uses a constant amount of extra space.
 */
#include <bits/stdc++.h>
using namespace std;

long long atMaxDist(vector<int> &nums, int d) {
  int i = 0, n = nums.size();
  long long cnt = 0;
  if (n < 3)
    return 0;

  for (int j = 0; j < n; j++) {
    while (nums[j] - nums[i] > d)
      i++;
    int len = j - i;
    if (len >= 2)
      cnt += 1LL * len * (len - 1) / 2;
  }
  return cnt;
}

int main() {
  int n, d;
  cin >> n >> d;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  long long ans = atMaxDist(nums, d);
  cout << ans << "\n";
}
