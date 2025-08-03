// program to print yes or no for n numbers
#include <bits/stdc++.h>
using namespace std;

int main() {
  const int maxN = 1e6;
  vector<bool> isPrime(maxN + 1, true);
  isPrime[0] = isPrime[1] = false;

  for (int i = 2; i * i <= maxN; i++) {
    if (isPrime[i]) {
      for (int j = i; i * j <= maxN; j++)
        isPrime[i * j] = false;
    }
  }

  int n;
  cin >> n;
  while (n--) {
    long long x;
    cin >> x;
    long long root = sqrtl(x);
    if (root * root == x && isPrime[root])
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}
