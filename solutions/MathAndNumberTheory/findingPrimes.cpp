// program to find primes using general sieve and reverse sieve then finding
// cout of common primes in both and printing them till n
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1;

vector<bool> isPrimeForward(MAX, true);
vector<bool> isPrimeReverse(MAX, true);
vector<int> commonCount(MAX);

void computeForwardSieve() {
  isPrimeForward[0] = isPrimeForward[1] = false;
  for (int i = 2; i * i < MAX; ++i) {
    if (isPrimeForward[i]) {
      for (int j = i * i; j < MAX; j += i) {
        isPrimeForward[j] = false;
      }
    }
  }
}

void computeReverseSieve() {
  isPrimeReverse[0] = isPrimeReverse[1] = false;
  for (int i = MAX - 1; i >= 2; --i) {
    if (isPrimeReverse[i]) {
      // Mark all proper factors (excluding i) as not prime
      for (int j = 1; j * j <= i; ++j) {
        if (i % j == 0) {
          if (j != i)
            isPrimeReverse[j] = false;
          int other = i / j;
          if (other != i && other != j)
            isPrimeReverse[other] = false;
        }
      }
    }
  }
}

void computeCommonCount() {
  int count = 0;
  for (int i = 0; i < MAX; ++i) {
    if (isPrimeForward[i] && isPrimeReverse[i]) {
      ++count;
    }
    commonCount[i] += count;
  }
}

int main() {
  computeForwardSieve();
  computeReverseSieve();
  computeCommonCount();

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << commonCount[n] << '\n';
  }

  return 0;
}
