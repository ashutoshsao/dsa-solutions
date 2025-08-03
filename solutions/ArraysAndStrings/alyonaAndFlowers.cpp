/*
 * Problem: Alyona and Flowers
 * Link: https://codeforces.com/problemset/problem/740/B
 * Problem Statement: Alyona has an array of flowers with associated mood values. Her mother suggests a set of subarrays. Alyona can choose any number of these subarrays. The total happiness is calculated by summing the mood values of flowers in the chosen subarrays. Each flower's value is counted as many times as it appears in the chosen subarrays. The goal is to maximize this total happiness.
 * Approach: The core idea is that we should only choose subarrays that have a positive sum of mood values. If a subarray's sum is negative, it would decrease the total happiness, so we ignore it. We can pre-calculate the prefix sums of the flower array to quickly find the sum of any subarray. We iterate through each of the suggested subarrays, calculate its sum, and if the sum is positive, we add it to our total happiness. The provided solution correctly identifies positive-sum subarrays and accumulates the total happiness by summing up the contributions of each flower based on how many positive-sum subarrays it belongs to.
 * Time Complexity: O(N * M) in the worst case because of the nested loops for updating the `times` array. A more optimized approach O(N+M) exists by directly adding the positive subarray sums.
 * Space Complexity: O(N) for the prefix sum and times arrays.
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<pair<int, int>> subarr(m);
  for (int i = 0; i < m; i++) {
    cin >> subarr[i].first >> subarr[i].second;
    subarr[i].first--;
    subarr[i].second--;
  }
  vector<int> Psum(n + 1);
  Psum[0] = 0;
  for (int i = 1; i < n + 1; i++) {
    Psum[i] = Psum[i - 1] + v[i - 1];
  }
  vector<int> times(n, 0);
  for (int i = 0; i < m; i++) {
    int l = subarr[i].first;
    int r = subarr[i].second;
    int sum = Psum[r + 1] - Psum[l];
    if (sum > 0) {
      for (int j = l; j <= r; j++) {
        times[j]++;
      }
    }
  }
  int total_happiness = 0;
  for (int i = 0; i < n; i++) {
    total_happiness += v[i] * times[i];
  }
  cout << total_happiness << "\n";
}