/*
Problem: SEXTUPLES
Link: https://www.spoj.com/problems/SEXTUPLE/
Problem Statement: Given a set of integers, find the number of sextuples (a, b, c, d, e, f) from the set that satisfy the equation `(a * b + c) / d - e = f`.
Approach: The solution generates all possible values for the left-hand side (LHS) `a * b + c` and the right-hand side (RHS) `(e + f) * d`. It then sorts the RHS values and, for each LHS value, uses binary search to find the number of matching RHS values.
Time Complexity: O(n^3 * log(n^3))
Space Complexity: O(n^3)
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n), LHS, RHS;
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          LHS.push_back(nums[i] * nums[j] + nums[k]);
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          if (nums[i] != 0) {
            RHS.push_back(nums[i] * (nums[j] + nums[k]));
          }
        }
      }
    }

    sort(RHS.begin(), RHS.end());

    long long cnt = 0;
    for (int x : LHS) {
      // find leftmost index of x in RHS
      int l = 0, h = (int)RHS.size() - 1;
      int ansLeft = -1;
      while (l <= h) {
        int m = l + (h - l) / 2;
        if (RHS[m] >= x) {
          if (RHS[m] == x)
            ansLeft = m;
          h = m - 1; // go left
        } else {
          l = m + 1;
        }
      }

      // find rightmost index of x in RHS
      l = 0;
      h = (int)RHS.size() - 1;
      int ansRight = -1;
      while (l <= h) {
        int m = l + (h - l) / 2;
        if (RHS[m] <= x) {
          if (RHS[m] == x)
            ansRight = m;
          l = m + 1; // go right
        } else {
          h = m - 1;
        }
      }

      if (ansLeft != -1 && ansRight != -1) {
        int freq = ansRight - ansLeft + 1;
        cnt += freq;
      }
    }
    cout << cnt << "\n";
  }
}
