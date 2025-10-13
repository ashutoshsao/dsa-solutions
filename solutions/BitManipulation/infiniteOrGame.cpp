/*
Problem: Infinite OR Game
Link: https://www.codechef.com/problems/LIKECS03
Problem Statement: Given a list of 'n' integers and an integer 'k', determine how many of the first 'k' powers of 2 (i.e., 2^0, 2^1, ..., 2^(k-1)) are missing from the given list.
Approach: The solution first sorts the input array to enable an efficient search. It then iterates through the powers of 2 from 2^0 to 2^(k-1). For each power of 2, it checks if that value exists in the sorted array using a two-pointer-like approach. A counter is maintained for the number of missing powers of 2.
Time Complexity: O(N log N) due to sorting the array.
Space Complexity: O(1) auxiliary space.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    sort(a.begin(), a.end()); // so we can use two-pointer style traversal

    int i = 0, missing = 0;
    for (int bit = 0; bit < k; bit++) {
      int mask = 1 << bit;
      while (i < n && a[i] < mask)
        i++; // move pointer forward
      if (i == n || a[i] != mask)
        missing++; // mask not found
    }

    cout << missing << "\n";
  }
  return 0;
}
