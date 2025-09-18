/*
Problem: Maximum Gap
Link: https://leetcode.com/problems/maximum-gap/
Problem Statement: Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0. You must write an algorithm that runs in linear time and uses linear extra space.
Approach: The solution uses a bucket-based approach to solve the problem in linear time. It first finds the minimum and maximum elements in the array. Then, it calculates the size of the buckets and the number of buckets needed. Each number from the input array is placed into a bucket. For each bucket, we only need to store the minimum and maximum values. The maximum gap will be the maximum difference between the minimum of the current bucket and the maximum of the previous bucket.
Time Complexity: O(n), where n is the size of the array. The algorithm iterates through the array a constant number of times.
Space Complexity: O(n), for the buckets. In the worst case, each element goes to a different bucket.
*/
#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> nums(n);
    int minNum = INT_MAX, maxNum = INT_MIN;

    for (int i = 0; i < n; ++i) {
      cin >> nums[i];
      minNum = min(minNum, nums[i]);
      maxNum = max(maxNum, nums[i]);
    }

    if (n < 2) {
      cout << 0 << "\n";
      continue;
    }

    if (minNum == maxNum) {
      cout << 0 << "\n";
      continue;
    }

    // Calculate gap using ceil
    int gap = max(1, (int)ceil((double)(maxNum - minNum) / (n - 1)));

    // Calculate bucket count based on gap
    int bucketCount = (maxNum - minNum) / gap + 1;

    vector<int> bucketMin(bucketCount, INT_MAX);
    vector<int> bucketMax(bucketCount, INT_MIN);

    for (int i = 0; i < n; i++) {
      int idx = (nums[i] - minNum) / gap;
      bucketMin[idx] = min(bucketMin[idx], nums[i]);
      bucketMax[idx] = max(bucketMax[idx], nums[i]);
    }

    int ans = 0;
    int prevMax = minNum;

    for (int i = 0; i < bucketCount; ++i) {
      // Check if bucket is empty by checking if bucketMax[i] == INT_MIN
      if (bucketMax[i] == INT_MIN)
        continue;

      ans = max(ans, bucketMin[i] - prevMax);
      prevMax = bucketMax[i];
    }

    cout << ans << "\n";
  }
}