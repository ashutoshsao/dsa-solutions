/*
 * Problem: Count of Range Sum
 * Link: https://leetcode.com/problems/count-of-range-sum/
 * Problem Statement: Given an integer array `nums` and two integers `lower` and `upper`, find the number of range sums that lie in `[lower, upper]` inclusive.
 * Approach: The solution uses a merge sort based approach. It calculates the prefix sums of the array. The core idea is that the sum of a range `[i, j]` is `prefix[j+1] - prefix[i]`. For each `j`, we need to find the number of `i`'s such that `lower <= prefix[j+1] - prefix[i] <= upper`. This is equivalent to `prefix[j+1] - upper <= prefix[i] <= prefix[j+1] - lower`. This problem is reduced to finding the number of elements in a range, which can be efficiently solved during the merge step of a merge sort.
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countRangeSum(vector<int> &nums, int lower, int upper) {
    int n = nums.size();
    vector<long long> prefix(n + 1, 0), tmp(n + 1);
    for (int i = 0; i < n; i++)
      prefix[i + 1] = prefix[i] + nums[i];
    long long cnt = 0;
    divideFunc(prefix, tmp, 0, n, lower, upper, cnt);
    return (int)cnt;
  }

private:
  void mergeFunc(vector<long long> &arr, vector<long long> &tmp, int start,
                 int mid, int end, long long lower, long long upper,
                 long long &cnt) {
    int low = start, high = start;
    for (int j = mid + 1; j <= end; ++j) {
      while (low <= mid && arr[low] < arr[j] - upper)
        low++;
      while (high <= mid && arr[high] <= arr[j] - lower)
        high++;
      cnt += (high - low);
    }
    int p1 = start, p2 = mid + 1, k = start;
    while (p1 <= mid && p2 <= end) {
      if (arr[p1] <= arr[p2])
        tmp[k++] = arr[p1++];
      else
        tmp[k++] = arr[p2++];
    }
    while (p1 <= mid)
      tmp[k++] = arr[p1++];
    while (p2 <= end)
      tmp[k++] = arr[p2++];
    for (int i = start; i <= end; i++)
      arr[i] = tmp[i];
  }

  void divideFunc(vector<long long> &arr, vector<long long> &tmp, int start,
                  int end, long long lower, long long upper, long long &cnt) {
    if (start >= end)
      return;
    int mid = (start + end) / 2;
    divideFunc(arr, tmp, start, mid, lower, upper, cnt);
    divideFunc(arr, tmp, mid + 1, end, lower, upper, cnt);
    mergeFunc(arr, tmp, start, mid, end, lower, upper, cnt);
  }
};

int main() {
  int n, lower, upper;
  cin >> n >> lower >> upper;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  Solution s;
  cout << s.countRangeSum(nums, lower, upper) << "\n";
  return 0;
}
