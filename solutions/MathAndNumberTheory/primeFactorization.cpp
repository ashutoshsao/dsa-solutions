#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt1 = 0, cnt2 = 0;
  cin >> n;
  int num = n; // imporatant as n is dynamically changing
  for (int i = 2; i * i <= num; i++) {
    while (n % i == 0) {
      cout << i << " ";
      n = n / i;
      cnt1++;
    }
    cnt2++;
  }
  if (n > 1)
    cout << n;
  cout << "\n" << cnt1 * cnt2 << "\n";
}
