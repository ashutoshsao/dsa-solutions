/*
Problem: B. Karen and Coffee
Link: https://codeforces.com/contest/816/problem/B
Problem Statement: Karen has n coffee recipes, each with a temperature range. A temperature is "admissible" if at least k recipes recommend it. Given q queries, each with a range [a, b], find the number of admissible temperatures in that range.
Approach: The solution uses a difference array and prefix sums. First, a difference array is used to mark the start and end of each recipe's temperature range. Then, a prefix sum is computed on the difference array to find the number of recipes covering each temperature. After that, another array is created to mark admissible temperatures (where coverage is >= k). Finally, a prefix sum is computed on the admissible temperatures array, allowing each query to be answered in O(1) by taking the difference of prefix sums.
Time Complexity: O(MAX + n + q), where MAX is the maximum temperature.
Space Complexity: O(MAX)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

  int n, k, q;
  cin >> n >> k >> q;

  const int MAX = 200000;
  vector<int> diff(MAX + 2, 0);

  // Step 1: Difference array for recipe ranges
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    diff[l] += 1;
    if (r + 1 <= MAX)
      diff[r + 1] -= 1;
  }

  // Step 2: Prefix sum to get coverage count at each temperature
  vector<int> cover(MAX + 2, 0);
  for (int i = 1; i <= MAX; i++)
    cover[i] = cover[i - 1] + diff[i];

  // Step 3: Mark admissible temperatures
  vector<int> admissible(MAX + 2, 0);
  for (int i = 1; i <= MAX; i++)
    admissible[i] = (cover[i] >= k) ? 1 : 0;

  // Step 4: Prefix sums of admissible counts
  vector<int> pref(MAX + 2, 0);
  for (int i = 1; i <= MAX; i++)
    pref[i] = pref[i - 1] + admissible[i];

  // Step 5: Answer queries in O(1)
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << pref[b] - pref[a - 1] << '\n';
  }

  return 0;
}
