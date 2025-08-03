// program to find number of divisors of a and b
#include <bits/stdc++.h>
using namespace std;

int main() {
  const int MAXN = 1e6;
  vector<int> primes;

  // Sieve of Eratosthenes
  vector<bool> is_prime(MAXN + 1, true);
  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i * i <= MAXN; i++) {
    if (is_prime[i]) {
      for (int j = i; i * j <= MAXN; j++) {
        is_prime[i * j] = false;
      }
    }
  }

  for (int i = 2; i <= MAXN; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }

  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;

    // Manual GCD
    long long x = a, y = b;
    while (y != 0) {
      long long temp = y;
      y = x % y;
      x = temp;
    }
    long long gcd = x;

    long long total_divisors = 1;
    for (int i = 0; i < primes.size() && 1LL * primes[i] * primes[i] <= gcd;
         i++) {
      int p = primes[i];
      int count = 0;
      while (gcd % p == 0) {
        count++;
        gcd /= p;
      }
      total_divisors *= (count + 1);
    }

    if (gcd > 1) {
      // gcd itself is a prime greater than 1
      total_divisors *= 2;
    }

    cout << total_divisors << '\n';
  }

  return 0;
}
