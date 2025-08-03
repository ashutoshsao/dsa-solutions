// program to color a and b in range differently if a or b is prime divisor of
// other minimuze no of colors
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> color(n + 2, 0); // color[2] to color[n+1]
  vector<bool> isPrime(n + 2, true);

  isPrime[0] = isPrime[1] = false;

  // Sieve of Eratosthenes
  for (int i = 2; i * i <= n + 1; i++) {
    if (isPrime[i]) {
      for (int j = i; i * j <= n + 1; j++) {
        isPrime[i * j] = false;
      }
    }
  }

  int k = (n <= 2) ? 1 : 2;

  for (int i = 2; i <= n + 1; i++) {
    if (isPrime[i])
      color[i] = 1;
    else
      color[i] = 2;
  }

  cout << k << "\n";
  for (int i = 2; i <= n + 1; i++) {
    cout << color[i] << " ";
  }
  cout << "\n";

  return 0;
}
