// programm to print only number of unique prime factoes of each element
// 10 12 14
// 2 2 2     ({2,5},{2,3},{2,7})
#include <bits/stdc++.h>
using namespace std;

int main() {
  int maxN = 1000000;
  vector<int> spf(maxN + 1);

  // Initialize spf array
  for (int i = 1; i <= maxN; i++) {
    spf[i] = i;
  }

  // Sieve to find smallest prime factors
  for (int i = 2; i * i <= maxN; i++) {
    if (spf[i] == i) { // i is prime (spf[i] == i)
      for (int j = i; i * j <= maxN; j++) {
        if (spf[i * j] == i * j) { // i*j hasn't been marked yet
          spf[i * j] = i;
        }
      }
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
      int num;
      cin >> num;

      set<int> uniquePrimeFactors;
      int temp = num;

      // Extract all prime factors using SPF
      while (temp > 1) {
        int primeFactor = spf[temp];
        uniquePrimeFactors.insert(primeFactor);

        // Remove all occurrences of this prime factor
        while (temp % primeFactor == 0) {
          temp /= primeFactor;
        }
      }

      cout << uniquePrimeFactors.size();
      if (i < n)
        cout << " ";
    }
    cout << endl;
  }

  return 0;
}
