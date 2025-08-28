/*
Problem: Smallest Good Base
Link: https://leetcode.com/problems/smallest-good-base/description/
Problem Statement: For a given integer `n`, find its smallest "good base" `k` (where `k >= 2`). A base `k` is "good" if the representation of `n` in that base consists only of the digit '1'.
Approach: The solution iterates through possible numbers of digits `m` from 63 down to 2. For each `m`, it uses binary search to find a base `k` such that the sum of the geometric series `1 + k + k^2 + ... + k^(m-1)` equals `n`. If such a `k` is found, it is the smallest good base because we are iterating `m` from largest to smallest. The search space for `k` is from 2 to `n-1`. To avoid overflow, the sum is calculated iteratively, with checks to ensure that the intermediate values do not exceed `n`.
Time Complexity: O((log n)^2). The outer loop runs about log n times, and the inner binary search also takes log n time.
Space Complexity: O(1), as the space used is constant regardless of the input size.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string smallestGoodBase(string n) {
    long long num = stoll(n);
    // fixing digits 63 to 2 (10^18 has max digits 63 digits at base 2 so 63 for
    // safe upper bound ) also 2 is the minimum base given in question taking
    // them in decreasing order as higher digits = lowerbase and we prune as we
    // get first match
    for (int i = 63; i >= 2; i--) {
      // search space : lowest base can be 2 and highest base for number can be
      // num-1
      long long l = 2, h = num - 1;

      while (l <= h) {
        long long m = l + (h - l) / 2;
        // val holds current total value x is current term
        long long val = 0, x = 1;
        bool flag = false;
        // looping over each digit 0th to ith will be x * m^i-1;
        for (int j = 0; j < i; j++) {
          // adding term to total
          val += x;
          // check if current total already above number then prune
          if (val > num) {
            flag = true;
            break;
          }
          // check if term remaining then if next term > remaining /x break to
          // preventing overflow
          if (j < i - 1 && (num - val) / x < m) {
            flag = true;
            break;
          }

          // since next term is safe then check if terms remaining and get next
          // term in x
          if (j < i - 1)
            x *= m;
        }
        // if match and no flag, found smallest good base
        if (val == num && !flag)
          return to_string(m);
        else if (val > num ||
                 flag) // if total > num or flag means base big, go left
          h = m - 1;
        else // if total < num means base small, go right
          l = m + 1;
      }
    }
    // if none satisfies num-1 will be smalles good base
    return to_string(num - 1);
  }
};

int main() {
  Solution sol;
  string n;
  cout << "Enter n: ";
  cin >> n;
  cout << "Smallest Good Base: " << sol.smallestGoodBase(n) << endl;
  return 0;
}
