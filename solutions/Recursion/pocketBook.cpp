
#include <bits/stdc++.h>
using namespace std;

int main() {
  const int MOD = 1e9 + 7;
  int n, m;
  cin >> n >> m;

  vector<string> names(n);
  for (int i = 0; i < n; i++) {
    cin >> names[i];
  }

  long long result = 1;

  for (int col = 0; col < m; col++) {
    set<char> uniqueLetters;
    for (int row = 0; row < n; row++) {
      uniqueLetters.insert(names[row][col]);
    }
    result = (result * uniqueLetters.size()) % MOD;
  }

  cout << result << endl;
  return 0;
}
