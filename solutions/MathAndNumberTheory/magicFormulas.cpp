/*
Problem: Magic Formulas
Link: https://codeforces.com/problemset/problem/424/C
Problem Statement: The problem asks to compute the value of Q, which is the XOR sum of n terms. The i-th term is p_i XORed with the XOR sum of (i mod j) for j from 1 to n.
Approach: The formula for Q can be simplified by separating the p_i terms and the (i mod j) terms.
Q = (p_1 XOR p_2 XOR ... XOR p_n) XOR (XOR sum of all (i mod j) for i, j from 1 to n).
The first part is the XOR sum of the input array p.
The second part is the XOR sum of (i mod j) for all i and j from 1 to n. This can be computed efficiently by iterating through j from 1 to n and, for each j, calculating the XOR sum of (i mod j) for i from 1 to n.
The sequence (i mod j) for i = 1, 2, ... is periodic. The pattern 1, 2, ..., j-1, 0 repeats.
The number of full patterns is n/j, and the length of the remaining pattern is n%j.
The XOR sum for a fixed j can be calculated in O(1) using a helper function that computes the XOR sum from 1 to x.
Time Complexity: O(n)
Space Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;

// Function to compute XOR of numbers from 1 to x in O(1)
long long xor1ToX(long long x) {
  if (x % 4 == 0)
    return x;
  if (x % 4 == 1)
    return 1;
  if (x % 4 == 2)
    return x + 1;
  return 0; // when x % 4 == 3
}

int main() {
  int n;
  cin >> n;
  vector<long long> p(n + 1);
  long long ans = 0;

  // Step 1: XOR all p[i]
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    ans ^= p[i];
  }

  // Step 2: Add the modulo pattern contribution
  for (int j = 1; j <= n; j++) {
    long long cnt = n / j; // how many full cycles
    long long rem = n % j; // leftover part

    // If number of full cycles is odd, one pattern remains
    if (cnt % 2 == 1)
      ans ^= xor1ToX(j - 1); // XOR of 1..(j-1)

    // Add the remaining partial pattern (0..rem)
    ans ^= xor1ToX(rem);
  }

  cout << ans << "\n";
  return 0;
}
