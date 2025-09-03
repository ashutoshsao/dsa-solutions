/*
Problem: D1. Magic Powder - 1
Link: https://codeforces.com/problemset/problem/670/D1
Problem Statement: Apollinaria wants to bake cookies. To bake one cookie, she needs n ingredients, with a_i grams required for the i-th ingredient. She currently has b_i grams of the i-th ingredient and k grams of magic powder. Each gram of magic powder can be converted into one gram of any of the n ingredients. The task is to find the maximum number of cookies she can bake.
Approach: The solution uses binary search on the number of cookies. For a given number of cookies m, we can check if it's possible to bake them. To bake m cookies, we need recipy[i] * m grams of each ingredient i. We already have have[i] grams. So, for each ingredient, we need to produce max(0, recipy[i] * m - have[i]) grams using magic powder. If the total magic powder required for all ingredients is less than or equal to k, then it's possible to bake m cookies. The binary search finds the maximum m for which this condition holds.
Time Complexity: O(n * log(max_cookies)), where max_cookies is the upper bound of the binary search. The isPossible function takes O(n) time.
Space Complexity: O(n) for storing the recipe and available ingredients.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(long long m, const vector<long long> &recipy,
                const vector<long long> &have, long long k) {
  long long needed = 0;
  int n = recipy.size();
  for (int i = 0; i < n; i++) {
    needed += max(0LL, recipy[i] * m - have[i]);
    if (needed > k)
      return false; // early exit
  }
  return true;
}

int main() {
  int n;
  long long k;
  cin >> n >> k;

  vector<long long> recipy(n), have(n);
  for (int i = 0; i < n; i++)
    cin >> recipy[i];
  for (int i = 0; i < n; i++)
    cin >> have[i];

  long long low = 0, high = 2000, ans = 0;

  while (low <= high) {
    long long mid = (low + high) / 2;
    if (isPossible(mid, recipy, have, k)) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  cout << ans << "\n";
  return 0;
}
