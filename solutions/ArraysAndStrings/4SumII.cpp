/*
 * Problem: 4Sum II
 * Link: https://leetcode.com/problems/4sum-ii/
 * Problem Statement: Given four integer arrays nums1, nums2, nums3, and nums4 of equal length n, find the number of tuples (i, j, k, l) such that nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0.
 * Approach: The solution uses a hash map to optimize the search. It first iterates through nums1 and nums2, calculating all possible sums nums1[i] + nums2[j]. The frequency of each sum is stored in a hash map. Then, it iterates through nums3 and nums4, calculating the sum nums3[k] + nums4[l]. For each of these sums, it checks if the negation of the sum exists in the hash map. If it does, the count associated with that negated sum is added to the total answer. This effectively finds all combinations that sum to zero.
 * Time Complexity: O(n^2), where n is the size of the lists. This is because we have two separate nested loops, each running n*n times.
 * Space Complexity: O(n^2) in the worst case, for storing all possible sums of pairs from the first two arrays in the hash map.
 */
class Solution {
public:
  long long fourSumCount(vector<int> &nums1, vector<int> &nums2,
                         vector<int> &nums3, vector<int> &nums4) {
    int n = nums1.size();
    unordered_map<long long, int> cnt;
    cnt.reserve(n * n * 2);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        long long s = (long long)nums1[i] + nums2[j];
        cnt[s]++;
      }
    }
    long long ans = 0;
    for (int k = 0; k < n; ++k) {
      for (int l = 0; l < n; ++l) {
        long long t = (long long)nums3[k] + nums4[l];
        auto it = cnt.find(-t);
        if (it != cnt.end())
          ans += it->second;
      }
    }
    return ans;
  }
};
