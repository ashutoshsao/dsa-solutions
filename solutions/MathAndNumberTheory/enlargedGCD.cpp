// Program to check if removing elements increases GCD, else print -1.

#include <iostream>
#include <numeric> // For std::gcd
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> array(n);

  // Read input and compute GCD of all elements
  int g = 0;
  for (int i = 0; i < n; ++i) {
    cin >> array[i];
    g = gcd(g, array[i]);
  }

  // Normalize array by dividing each element by the GCD
  for (int &x : array)
    x /= g;

  // Find the maximum value in the normalized array
  int max_val = 0;
  for (int val : array)
    if (val > max_val)
      max_val = val;

  // Initialize smallest prime factor (SPF) and prime frequency arrays
  vector<int> spf(max_val + 1, 0);
  vector<int> prime_count(max_val + 1, 0);

  // Sieve to compute smallest prime factor for every number up to max_val
  for (int i = 2; i <= max_val; ++i) {
    if (spf[i] == 0) {
      for (int j = i; j <= max_val; j += i) {
        if (spf[j] == 0)
          spf[j] = i;
      }
    }
  }

  // Count frequency of prime factors across all elements
  for (int x : array) {
    while (x > 1) {
      int p = spf[x];
      prime_count[p]++;
      while (x % p == 0)
        x /= p;
    }
  }

  // Find the maximum frequency among all prime factors
  int max_freq = 0;
  for (int freq : prime_count)
    if (freq > max_freq)
      max_freq = freq;

  // Output the result
  if (max_freq == 0)
    cout << -1 << endl;
  else
    cout << n - max_freq << endl;

  return 0;
}
