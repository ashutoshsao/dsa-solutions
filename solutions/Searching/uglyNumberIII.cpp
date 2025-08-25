/*
Problem: Ugly Number III
Link: https://leetcode.com/problems/ugly-number-iii/
Problem Statement: Write a program to find the n-th ugly number. Ugly numbers are positive integers which are divisible by a or b or c.
Approach: The problem is solved using binary search on the answer. We are looking for the smallest integer x such that there are at least n ugly numbers less than or equal to x. The number of ugly numbers up to a given number `mid` is calculated using the Principle of Inclusion-Exclusion:
count(mid) = (mid/a) + (mid/b) + (mid/c) - (mid/lcm(a,b)) - (mid/lcm(a,c)) - (mid/lcm(b,c)) + (mid/lcm(a,b,c)).
If count(mid) >= n, we search in the lower half [1, mid], otherwise we search in the upper half [mid+1, high].
Time Complexity: O(log(2*10^9)) which is effectively O(1) as the number of iterations is constant. The gcd and lcm calculations are also very fast.
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

long long ugluNumCount(long long x, long long a, long long b, long long c) {
  return x / a + x / b + x / c - x / lcm(a, b) - x / lcm(b, c) - x / lcm(a, c) +
         x / lcm(lcm(a, b), c);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, a, b, c;
    cin >> n >> a >> b >> c;

    long long l = 1, h = 2e9;

    while (l < h) {
      long long m = l + (h - l) / 2;
      if (ugluNumCount(m, a, b, c) < n)
        l = m + 1;
      else
        h = m;
    }

    long long ans = l;
    cout << ans << "\n";
  }
  return 0;
}

