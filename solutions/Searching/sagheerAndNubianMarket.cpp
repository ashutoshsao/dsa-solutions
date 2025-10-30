/*
 * Problem: Sagheer and Nubian Market
 * Link: https://codeforces.com/problemset/problem/812/C
 * Problem Statement: The user is asked to find the maximum number of items Sagheer can buy given a budget S. The cost of each item i is its base cost a_i plus i * k, where k is the total number of items being bought. They also need to find the minimum cost to purchase k items.
 * Approach: The solution uses binary search on the number of items k. For a given k, it calculates the cost of each item, sorts the costs, and finds the sum of the smallest k costs. If this sum is within the budget, it tries a larger k; otherwise, it tries a smaller k.
 * Time Complexity: O(n log n * log n)
 * Space Complexity: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

pair<int, long long> isPossible(vector<int> &nums, int items) {

  int n = nums.size();
  vector<long long> costs(n);
  for (int i = 0; i < n; i++) {
    costs[i] = nums[i] + 1LL * (i + 1) * items;
  }

  sort(costs.begin(), costs.end());
  long long sum = 0;
  for (int i = 0; i < items; i++) {
    sum += costs[i];
  }

  return {items, sum};
}

int main() {
  int n, s;
  cin >> n >> s;
  vector<int> prices(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> prices[i];
  }

  int l = 0, h = n, bestK = 0;
  long long bestCost = 0;
  while (l <= h) {
    int m = l + (h - l) / 2;
    auto [k, costs] = isPossible(prices, m);
    if (costs <= s) {
      bestK = k;
      bestCost = costs;
      l = m + 1;
    } else {
      h = m - 1;
    }
  }
  cout << bestK << " " << bestCost << "\n";
  return 0;
}
