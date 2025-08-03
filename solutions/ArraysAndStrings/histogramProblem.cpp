/*
* Problem: Trapping Rain Water
* Link: https://leetcode.com/problems/trapping-rain-water/
* Problem Statement: Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
* Approach: The approach used here is a dynamic programming solution. It pre-computes the maximum height of a bar to the left and right of each bar.
* 1. Create a `Pmax` array (prefix max) where `Pmax[i]` stores the maximum height to the left of or at index `i`.
* 2. Create a `Smax` array (suffix max) where `Smax[i]` stores the maximum height to the right of or at index `i`.
* 3. Iterate through the elevation map from the second to the second-to-last bar (from index 1 to n-2). For each bar `i`, the amount of water trapped above it is `min(Pmax[i-1], Smax[i+1]) - v[i]`. If this value is positive, add it to the total sum.
* Time Complexity: O(n)
* Space Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, sum = 0;
  cin >> n;
  vector<int> v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<int> Pmax(n);
  Pmax[0] = v[0];
  for (i = 1; i < n; i++) {
    Pmax[i] = max(Pmax[i - 1], v[i]);
  }
  vector<int> Smax(n);
  Smax[n - 1] = v[n - 1];
  for (i = n - 2; i >= 0; i--) {
    Smax[i] = max(Smax[i + 1], v[i]);
  }
  for (int i = 1; i < n - 1; i++) {
    int deciding_h = min(Pmax[i - 1], Smax[i + 1]);
    if (deciding_h > v[i]) {
      sum += deciding_h - v[i];
    }
  }
  cout << "the total water stored is = " << sum << "\n";
}
