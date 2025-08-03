// program to rotate matrix 90 degrees (clockwise), reverse colomn wise to
// rotate (anticlock)
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<int>> twodv(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> twodv[i][j];
    }
  }
  int temp;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (i != j) {
        temp = twodv[i][j];
        twodv[i][j] = twodv[j][i];
        twodv[j][i] = temp;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    reverse(twodv[i].begin(), twodv[i].end());
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << twodv[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
