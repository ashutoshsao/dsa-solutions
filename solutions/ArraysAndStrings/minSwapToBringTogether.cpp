#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  int maxLegal = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] <= k)
      maxLegal++;
  }
  int cnt = 0;
  for (int i = 0; i < maxLegal; i++) {
    if (arr[i] <= k)
      cnt++;
  }
  int maxCnt = cnt;
  for (int i = maxLegal; i < n; i++) {
    if (arr[i] <= k) {
      cnt++;
    }
    if (arr[i - maxLegal] <= k) {
      cnt--;
    }
    maxCnt = max(maxCnt, cnt);
  }
  cout << maxLegal - maxCnt << "\n";
}
