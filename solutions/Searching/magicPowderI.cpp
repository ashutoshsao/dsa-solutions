/*
 * Problem: Magic Powder - 1
 * Link: https://codeforces.com/problemset/problem/670/D1
 * Problem Statement: Given `n` ingredients, the required amount of each ingredient to bake one cookie, the amount of each ingredient already possessed, and `k` grams of magic powder (which can be converted to any ingredient), find the maximum number of cookies that can be baked.
 * Approach: The problem can be solved using binary search on the number of cookies. For a given number of cookies `x`, we can check if it's possible to bake them. To bake `x` cookies, we need `need[i] * x` of ingredient `i`. If we have `have[i]` of that ingredient, we need to use magic powder for the deficit `need[i] * x - have[i]`. The total magic powder required is the sum of these deficits for all ingredients. If the total magic powder required is less than or equal to `k`, it's possible to bake `x` cookies. The binary search helps us find the maximum `x`.
 * Time Complexity: O(n * log(high)), where high is the upper bound for the number of cookies.
 * Space Complexity: O(n) to store the ingredient requirements and possessions.
 */
#include <bits/stdc++.h>
using namespace std;

bool isPossible(const vector<int> &need, const vector<int> &have, int k,
                int x) {
  long long requiredPowder = 0;
  for (int i = 0; i < need.size(); i++) {
    long long totalNeed = 1LL * need[i] * x;
    if (totalNeed > have[i]) {
      requiredPowder += totalNeed - have[i];
      if (requiredPowder > k)
        return false;
    }
  }
  return requiredPowder <= k;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> need(n), have(n);
  for (int &x : need) {
    cin >> x;
  }
  for (int &y : have) {
    cin >> y;
  }
  long long l = 0, h = 2e9; // high can be large, not just n

  while (l <= h) {
    long long mid = l + (h - l) / 2;
    if (isPossible(need, have, k, mid))
      l = mid + 1;
    else
      h = mid - 1;
  }
  cout << h << "\n";
  return 0;
}
