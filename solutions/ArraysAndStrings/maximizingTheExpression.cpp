/*
Problem: Maximize The Expression
Link: Not available from a standard platform. This is a classic dynamic programming problem.
Problem Statement: Given an array `arr` and three numbers `p`, `q`, and `r`, find the maximum value of `p*arr[i] + q*arr[j] + r*arr[k]` such that `i < j < k`.
Approach: The solution uses dynamic programming to solve the problem in linear time. It precomputes two arrays:
1. `Pmax`: `Pmax[i]` stores the maximum value of `p*arr[x]` for all `x <= i`.
2. `Smax`: `Smax[i]` stores the maximum value of `r*arr[x]` for all `x >= i`.
After pre-computation, it iterates from `j = 1` to `n-2` and for each `j`, it calculates `Pmax[j-1] + q*arr[j] + Smax[j+1]`. The maximum value found during this iteration is the answer.
Time Complexity: O(n), as it involves three passes through the array.
Space Complexity: O(n), for the `Pmax` and `Smax` arrays.
*/
// this program is to maximize the expression max(p*arr[i]+q*arr[j]+r*arr[k])
// ,i<j<k ; for change in constrains i<=j<=k change final loop to 0 to n-2 and
// Pmax[i]+q*v[i]+Smax[i]
#include <bits/stdc++.h>
#include <climits>
using namespace std;
int main() {
  long long n, p, q, r;
  cin >> n >> p >> q >> r;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  vector<long long> Pmax(n);
  Pmax[0] = p * v[0];
  for (int i = 1; i < n; i++) {
    Pmax[i] = max(Pmax[i - 1], p * v[i]);
  }

  vector<long long> Smax(n);
  Smax[n - 1] = r * v[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    Smax[i] = max(Smax[i + 1], r * v[i]);
  }
  long long ans = LLONG_MIN;
  for (int i = 1; i < n - 1; i++) {
    ans = max(ans, Pmax[i - 1] + (q * v[i]) + Smax[i + 1]);
  }
  cout << ans << "\n";
  return 0;
}