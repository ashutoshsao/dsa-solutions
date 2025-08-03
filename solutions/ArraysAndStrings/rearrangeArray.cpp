#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  for (int i = 0; i < n; i++) {
    int old_val = v[i] % n;
    v[old_val] = ((long long)n * i) + v[old_val];
  }

  for (int i = 0; i < n; i++) {
    v[i] = v[i] / n;
  }

  for (int i = 0; i < n; i++) {
    cout << v[i] << " ";
  }
  cout << '\n';
}
