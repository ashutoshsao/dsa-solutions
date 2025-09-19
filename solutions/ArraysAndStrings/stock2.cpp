/*
Problem: Best Time to Buy and Sell Stock III
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
Problem Statement: You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`-th day. Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
Approach: The provided solution is a brute-force approach. It calculates the maximum profit for one transaction (`ans1`) and then uses three nested loops to find the maximum profit for two transactions (`ans2`). The outer loops iterate through all possible buy and sell days for the first transaction, and the inner loop iterates through all possible buy and sell days for the second transaction. The final answer is the maximum of `ans1` and `ans2`.
Time Complexity: O(n^3), due to the three nested loops.
Space Complexity: O(n), for the `Smax` array.
*/
#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
  int n, i;
  cin >> n;
  vector<int> v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }

  if (n < 2) {
    cout << "0\n";
    return 0;
  }

  vector<int> Smax(n);
  Smax[n - 1] = v[n - 1];
  for (i = n - 2; i >= 0; i--) {
    Smax[i] = max(Smax[i + 1], v[i]);
  }

  int ans1 = 0;
  for (int i = 0; i < n - 1; i++) {
    if (Smax[i + 1] - v[i] > ans1) {
      ans1 = Smax[i + 1] - v[i];
    }
  }

  int ans2 = INT_MIN;
  for (i = 0; i < n - 3; i++) {
    for (int j = i + 1; j < n - 2; j++) {
      for (int k = j + 1; k < n - 1; k++) {
        ans2 = max((v[j] - v[i]) + (Smax[k + 1] - v[k]), ans2);
      }
    }
  }

  int ans = max(ans1, ans2);
  cout << ans << "\n";
  return 0;
}