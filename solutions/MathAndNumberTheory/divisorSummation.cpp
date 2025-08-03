// program to print sum of perfect divisors of num
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    if (n == 1) {
      cout << 0 << "\n";
      continue;
    }

    long long sum = 1;

    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        if (i * i == n) {
          sum += i;
        } else {
          sum += i + n / i;
        }
      }
    }

    cout << sum << "\n";
  }
  return 0;
}
