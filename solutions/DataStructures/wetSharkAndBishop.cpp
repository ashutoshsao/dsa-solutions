#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  unordered_map<int, int> diag1; // for x - y (right-tilted)
  unordered_map<int, int> diag2; // for x + y (left-tilted)

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    diag1[x - y]++;
    diag2[x + y]++;
  }

  long long res = 0;

  for (auto &it : diag1) {
    int cnt = it.second;
    res += 1LL * cnt * (cnt - 1) / 2;
  }

  for (auto &it : diag2) {
    int cnt = it.second;
    res += 1LL * cnt * (cnt - 1) / 2;
  }

  cout << res << endl;
  return 0;
}
