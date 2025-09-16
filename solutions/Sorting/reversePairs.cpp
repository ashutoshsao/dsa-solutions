/*
 * Problem: Reverse Pairs
 * Link: https://leetcode.com/problems/reverse-pairs/
 * Problem Statement: Given an integer array nums, return the number of reverse pairs in it. A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].
 * Approach: The solution uses a divide and conquer approach, specifically a modified merge sort. The `divideFunc` recursively splits the array into halves. The `mergeFunc` is where the counting happens. While merging the two sorted halves, for each element `arr[j]` in the right half, we count how many elements `arr[k]` in the left half satisfy the condition `arr[k] > 2 * arr[j]`. This count is added to the total. The merging process itself is a standard merge sort merge operation.
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void mergeFunc(vector<int> &arr, vector<int> &tmp, int start, int m, int end,
                 long long &cnt) {
    int p1 = start;
    int p2 = m + 1;
    int c = start;

    int k = p1;
    for (int j = p2; j <= end; j++) {
      while (k <= m && (long long)arr[k] <= 2LL * arr[j])
        k++;
      cnt += (m - k + 1);
    }

    while (p1 <= m && p2 <= end) {
      if (arr[p1] <= arr[p2])
        tmp[c++] = arr[p1++];
      else
        tmp[c++] = arr[p2++];
    }
    while (p1 <= m)
      tmp[c++] = arr[p1++];
    while (p2 <= end)
      tmp[c++] = arr[p2++];
    for (int i = start; i <= end; i++)
      arr[i] = tmp[i];
  }

  void divideFunc(vector<int> &arr, vector<int> &tmp, int start, int end,
                  long long &cnt) {
    if (start == end)
      return;
    int m = (start + end) / 2;
    divideFunc(arr, tmp, start, m, cnt);
    divideFunc(arr, tmp, m + 1, end, cnt);
    mergeFunc(arr, tmp, start, m, end, cnt);
  }

  int reversePairs(vector<int> &nums) {
    long long cnt = 0;
    int n = nums.size();
    vector<int> tmp(n);
    divideFunc(nums, tmp, 0, n - 1, cnt);
    return (int)cnt;
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  Solution sol;
  cout << sol.reversePairs(nums) << "\n";
  return 0;
}
