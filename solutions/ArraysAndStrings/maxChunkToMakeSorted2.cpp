#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int maxm = INT_MIN, cnt = 0;
  for (int i = 0; i < n; i++) {
    maxm = max(maxm, v[i]);
    if (maxm == i) {
      cnt++;
    }
  }
  cout << cnt << "\n";
}
