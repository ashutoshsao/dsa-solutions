/*
 * Problem: Little Girl and Maximum Sum
 * Link: https://codeforces.com/contest/276/problem/C
 * Problem Statement: You are given an array of n integers and q queries. Each query is a range [li, ri]. You need to find the maximum possible sum of elements in these ranges by rearranging the array elements.
 * Approach: To maximize the sum, the largest numbers should be placed at indices that are queried most often.
 * 1. Calculate the frequency of each index being included in the query ranges. This can be done efficiently in O(n+q) using a difference array (prefix sums).
 * 2. Sort the original array in descending order.
 * 3. Sort the frequency array in descending order.
 * 4. The maximum sum is the dot product of the sorted values and sorted frequencies.
 * Time Complexity: O(n log n + q) for sorting the values and frequencies.
 * Space Complexity: O(n) for storing the frequency array.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<long long> values(n);
  for (auto &x : values)
    cin >> x;

  vector<long long> freq(n + 2, 0);
  while (q--) {
    int l, r;
    cin >> l >> r;
    freq[l - 1]++; // add at l-1 (0-based)
    freq[r]--;     // subtract after r-1
  }

  for (int i = 1; i < n; i++)
    freq[i] += freq[i - 1]; // prefix -> actual counts

  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](int a, int b) { return freq[a] > freq[b]; });

  sort(values.rbegin(), values.rend()); // largest values first

  long long ans = 0;
  for (int i = 0; i < n; i++)
    ans += values[i] * freq[idx[i]];

  cout << ans << '\n';
}
