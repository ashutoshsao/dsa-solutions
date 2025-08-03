// program to do segmented sieve where left and right number is till 10^12
#include <bits/stdc++.h>
using namespace std;

vector<int> getPrimes() {
  int maxN = 1e6;
  vector<bool> isPrime(maxN + 1, true);
  isPrime[0] = isPrime[1] = false;

  for (int i = 2; i * i <= maxN; i++) {
    if (isPrime[i]) {
      for (int j = i; i * j <= maxN; j++) {
        isPrime[i * j] = false;
      }
    }
  }

  vector<int> primes;
  for (int i = 2; i <= maxN; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
  }

  return primes;
}

int main() {
  int t;
  cin >> t;
  vector<int> primes = getPrimes();

  while (t--) {
    long long l, r;
    cin >> l >> r;
    vector<bool> isPrime(r - l + 1, true);

    for (int i = 0; i < primes.size(); i++) {
      long long k = (l + primes[i] - 1) / primes[i];

      for (long long j = max(k, 2LL); primes[i] * j <= r; j++) {
        isPrime[primes[i] * j - l] = false;
      }
    }

    if (l == 1)
      isPrime[0] = false;

    for (int i = 0; i <= r - l; i++) {
      if (isPrime[i]) {
        cout << (l + i) << " ";
      }
    }
    cout << "\n";
  }

  return 0;
}
