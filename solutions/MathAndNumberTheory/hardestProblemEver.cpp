#include <bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b) {
  long long maxNum = max(a, b);
  long long minNum = min(a, b);
  if (minNum == 0)
    return maxNum;
  while (maxNum % minNum != 0) {
    long long temp = maxNum;
    maxNum = minNum;
    minNum = temp % minNum;
  }
  return minNum;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    long long gcd = GCD(v[0], v[1]);
    for (int i = 1; i < n; i++) {
      gcd = GCD(gcd, v[i]);
    }
    if (gcd == 1)
      cout << 1 << "\n";
    else
      cout << 0 << "\n";
  }
}
