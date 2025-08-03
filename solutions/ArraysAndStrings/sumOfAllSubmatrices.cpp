#include <bits/stdc++.h>
using namespace std;

int main() {
  int mod = 1e9 + 7;
  int n, m;
  cin >> n >> m;

  vector<vector<int>> matrix(n, vector<int>(m));
  int *ptr = &matrix[0][0];

  // Taking inputs using pointer arithmetic which treats 2D array as 1D
  for (int i = 0; i < m * n; i++) {
    cin >> *(ptr + i);
  }

  long long sum = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      long long factor1 = (long long)(i + 1) * (n - i);
      long long factor2 = (long long)(j + 1) * (m - j);
      long long multiplier = (factor1 * factor2) % mod;
      long long contribution = multiplier * matrix[i][j];
      sum = (sum + contribution) % mod;
    }
  }

  cout << sum << endl;
  return 0;
}
