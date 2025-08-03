// program to print the count of numbers from 1 to n that has distinct 2 prime
// factors
#include <bits/stdc++.h>
using namespace std;
int main() {
  const int MAXN = 1000000;
  vector<int> primeCount(MAXN + 1, 0);
  vector<int> prefix(MAXN + 1, 0);

  // Step 1: Sieve to count distinct prime factors
  for (int i = 2; i <= MAXN; i++) {
    if (primeCount[i] == 0) {
      for (int j = i; j <= MAXN; j += i) {
        primeCount[j]++;
      }
    }
  }

  // Step 2: Build prefix sum for numbers with exactly 2 prime factors
  for (int i = 1; i <= MAXN; i++) {
    prefix[i] = prefix[i - 1] + (primeCount[i] == 2);
  }

  // Step 3: Answer queries in O(1)
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << prefix[n] << "\n";
  }

  return 0;
}
