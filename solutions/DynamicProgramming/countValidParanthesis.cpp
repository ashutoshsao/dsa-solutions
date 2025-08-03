#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int main() {
  int n = 501;
  vector<long long> cnt(n, -1);
  cnt[0] = cnt[1] = 1;
  for (int i = 2; i < n; i++) {
    cnt[i] = 0;
    for (int j = 0; j < i; j++) {
      cnt[i] = (cnt[i] + (cnt[j] * cnt[i - 1 - j]) % mod) % mod;
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 0) {
      cout << 1 << "\n";
      continue;
    }
    if (n % 2 != 0) {
      cout << -1 << "\n";
      continue;
    }
    if (n > 1000) {
      cout << "Error" << "\n";
      continue;
    }
    // Main logic here
    cout << cnt[n / 2] << "\n";
  }
  return 0;
}
