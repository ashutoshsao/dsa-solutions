// program to find product of primes in a range L and R inclusive
#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 1;
const int mod = 1e9 + 7;
vector<int> basePrimes;

// sieve up to 1e6
void sieve() {
  vector<bool> isPrime(maxN, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i * i < maxN; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j < maxN; j += i) {
        isPrime[j] = false;
      }
    }
  }
  // collect all primes important to have in different look to refister all
  // primes
  for (int i = 2; i < maxN; i++) {
    if (isPrime[i]) {
      basePrimes.push_back(i);
    }
  }
}

vector<long long> getPrimesInRange(long long l, long long r) {
  vector<bool> isPrime(r - l + 1, true);

  // handle edge case for 1
  if (l == 1) {
    isPrime[0] = false;
  }

  // use segmented sieve
  for (int i = 0; i < basePrimes.size(); i++) {
    long long p = basePrimes[i];

    // find first multiple of p in range [l, r]
    long long start = max(p * p, ((l + p - 1) / p) * p);

    // mark multiples as composite
    for (long long j = start; j <= r; j += p) {
      isPrime[j - l] = false;
    }
  }

  vector<long long> primes;
  for (long long i = l; i <= r; i++) {
    if (isPrime[i - l]) {
      primes.push_back(i);
    }
  }
  return primes;
}

long long productOfPrimes(const vector<long long> &primes) {
  long long prod = 1;
  for (int i = 0; i < primes.size(); i++) {
    prod = (prod * primes[i]) % mod;
  }
  return prod;
}

int main() {
  sieve();
  int t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    vector<long long> primes = getPrimesInRange(l, r);
    cout << productOfPrimes(primes) << "\n";
  }
  return 0;
}
