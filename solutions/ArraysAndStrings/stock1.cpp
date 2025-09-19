/*
Problem: Best Time to Buy and Sell Stock
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Problem Statement: You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`-th day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
Approach: The solution uses a pre-computation approach. It first creates a suffix-max array `Smax`, where `Smax[i]` stores the maximum stock price from day `i` to the last day. Then, it iterates through the `prices` array and for each day `i`, it calculates the potential profit by subtracting the price on day `i` from the maximum price available from the next day onwards (`Smax[i+1]`). The maximum of these potential profits is the answer.
Time Complexity: O(n), as it involves two passes through the array.
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
  vector<int> Smax(n);
  Smax[n - 1] = v[n - 1];
  for (i = n - 2; i >= 0; i--) {
    Smax[i] = max(Smax[i + 1], v[i]);
  }
  int diff = 0;
  for (int i = 0; i < n - 1; i++) {
    if (Smax[i + 1] - v[i] > diff) {
      diff = Smax[i + 1] - v[i];
    }
  }
  int profit = 0;
  if (diff > 0) {
    profit = diff;
  }
  cout << profit << "\n";
  return 0;
}