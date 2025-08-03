/*
 * Problem: Counting Triplets
 * Link: (No specific link, a general competitive programming problem)
 * Problem Statement: Given an array of integers and a number m, find the number of triplets (a, b, c) such that (a + b + c) is divisible by m.
 * Approach: We use a frequency map (bucket) to store the counts of remainders of each number in the array when divided by m. Then, we iterate through all possible pairs of remainders (i, j) and calculate the required third remainder k = (m - (i + j) % m) % m. We then use combinations to count the number of triplets for each valid set of remainders (i, j, k), handling cases where i, j, and k are the same or different.
 * Time Complexity: O(n + m^2), where n is the number of elements in the array and m is the divisor.
 * Space Complexity: O(m) for the frequency map.
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, num;
  cin >> n >> m;
  vector<int> bucket(m, 0);
  for (int i = 0; i < n; i++) {
    cin >> num;
    bucket[num % m]++;
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    for (int j = i; j < m; j++) {
      int k;
      if ((i + j) % m == 0)
        k = 0;
      else
        k = m - ((i + j) % m);
      if (k < j)
        continue;
      // picking from same bucket
      if (i == j && j == k) {
        ans += (bucket[i] * (bucket[i] - 1) * (bucket[i] - 2)) / 6;
      } else if (i == j) { // 3 if
        ans += ((bucket[i] * (bucket[i] - 1)) / 2) * bucket[k];
      } else if (i == k) {
        ans += ((bucket[i] * (bucket[i] - 1)) / 2) * bucket[j];
      } else if (j == k) {
        ans += ((bucket[j] * (bucket[j] - 1)) / 2) * bucket[i];
      } else {
        ans += bucket[i] * bucket[j] * bucket[k];
      }
    }
  }
  cout << ans << "\n";
}
