#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<int> Smax(n);
  Smax[n - 1] = v[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    Smax[i] = max(Smax[i + 1], v[i]);
  }
  int ans1 = 0;
  for (int i = 0; i < n - 1; i++) {
    if (Smax[i + 1] - v[i] > ans1) {
      ans1 = Smax[i + 1] - v[i];
    }
  }
  vector<int> leftProfit(n, 0);
  vector<int> rightProfit(n, 0);
  int minPrice = v[0];
  for (int i = 1; i < n - 2; i++) {
    minPrice = min(minPrice, v[i]);
    leftProfit[i] = max(leftProfit[i - 1], v[i] - minPrice);
  }
  int maxPrice = v[n - 1];
  for (int i = n - 2; i >= 2; i--) {
    maxPrice = max(maxPrice, v[i]);
    rightProfit[i] = max(rightProfit[i + 1], maxPrice - v[i]);
  }
  int ans2 = 0;
  for (int i = 0; i < n - 2; i++) {
    ans2 = max(ans2, leftProfit[i] + rightProfit[i + 1]);
  }
  int ans = max(ans1, ans2);
  cout << ans << "\n";
  return 0;
}
