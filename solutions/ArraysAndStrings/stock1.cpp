#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
  int n, i;
  cin >> n;
  vector<int> v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<int> Smax(n);
  Smax[n - 1] = v[n - 1];
  for (i = n - 2; i >= 0; i--) {
    Smax[i] = max(Smax[i + 1], v[i]);
  }
  int diff = 0;
  for (int i = 0; i < n - 1; i++) {
    if (Smax[i + 1] - v[i] > diff) {
      diff = Smax[i + 1] - v[i];
    }
  }
  int profit = 0;
  if (diff > 0) {
    profit = diff;
  }
  cout << profit << "\n";
  return 0;
}
