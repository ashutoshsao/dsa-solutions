#include <bits/stdc++.h>
using namespace std;
#include <climits>
int main() {
  int n, k;
  cin >> n >> k;
  int z = k % n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  if (n > 1) {
    reverse(v.begin(), (v.end() - z));
    reverse(v.end() - z, v.end());
    reverse(v.begin(), v.end());
  }
  for (int i = 0; i < n; i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}
