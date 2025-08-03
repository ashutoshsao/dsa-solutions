// In this program we will find prime numbers till N using the popular math
// algorithm called Sieve Of Eratosthenes
// adding spf (smallest prime factor) array in algo

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<bool> isPrime(n + 1, true);
  vector<int> spf(n + 1, -1);

  isPrime[0] = isPrime[1] = false;

  for (int i = 2; i <= n; i++) {
    spf[i] = i; // initialize spf[i] = i for all numbers
  }

  for (int i = 2; i * i <= n; ++i) {
    if (isPrime[i]) {
      for (int j = i; j * i <= n; j++) {
        if (spf[j * i] == j * i) {
          spf[j * i] = i; // assign spf for untouched composites
        }
        isPrime[j * i] = false; // mark composite
      }
    }
  }

  // print primes
  for (int i = 2; i <= n; i++) {
    if (isPrime[i]) {
      cout << i << " ";
    }
  }
  cout << "\n";
  // print factorization using spf
  for (int i = 2; i <= n; i++) {
    int j = i;
    cout << i << " = ";
    map<int, int> freq;
    while (j > 1) {
      cout << spf[j];
      int temp = spf[j];
      freq[temp]++;
      j /= spf[j];
      if (j > 1)
        cout << " * ";
    }
    int total = 1;
    for (auto it = freq.begin(); it != freq.end(); it++) {
      total *= (it->second + 1);
    }
    cout << " total divisors : " << total;
    cout << "\n";
  }

  return 0;
}
