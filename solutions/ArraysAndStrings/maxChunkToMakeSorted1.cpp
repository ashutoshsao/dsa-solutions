#include <bits/stdc++.h>
#include <ostream>
#include <vector>
using namespace std;
bool canBeChunked(int i, int j, vector<int> &v) {
  int cnt = 0;
  for (int k = i; k <= j; k++) {
    if (v[k] >= i && v[k] <= j) {
      cnt++;
    }
  }
  if (cnt == j - i + 1)
    return true;
  else
    return false;
}
int main() {
  int n, i, j, ans = 0;
  cin >> n;
  vector<int> v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }
  i = 0;
  while (i < n) {
    for (j = i; j < n; j++) {
      if (canBeChunked(i, j, v))
        break;
    }
    i = j + 1;
    ans++;
  }
  cout << ans << "\n";
}
