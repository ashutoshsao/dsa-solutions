/*
 * Problem: First Bad Version
 * Link: https://leetcode.com/problems/first-bad-version/description/
 * Problem Statement: You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad. Suppose you have `n` versions `[1, 2, ..., n]` and you want to find out the first bad one, which causes all the following ones to be bad. You are given an API `bool isBadVersion(version)` which returns whether `version` is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
 * Approach: The solution uses binary search to find the first bad version. It initializes two pointers, `low` and `high`, to the first and last versions, respectively. In each iteration, it calculates the middle version `mid`. If `mid` is not a bad version, it means the first bad version must be after `mid`, so it updates `low` to `mid + 1`. Otherwise, if `mid` is a bad version, it might be the first bad version, so it updates `high` to `mid`. The loop continues until `low` and `high` meet, at which point `low` will be the first bad version.
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

// Mock API (LeetCode provides this)
int firstBad = 4; // Example: suppose version 4 is the first bad version
bool isBadVersion(int version) { return version >= firstBad; }

class Solution {
public:
  int firstBadVersion(int n) {
    int low = 1, high = n;
    while (low < high) {
      int mid = low + (high - low) / 2;
      if (!isBadVersion(mid)) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }
};

int main() {
  Solution sol;
  int n = 10; // example
  cout << "First bad version: " << sol.firstBadVersion(n) << endl;
  return 0;
}
