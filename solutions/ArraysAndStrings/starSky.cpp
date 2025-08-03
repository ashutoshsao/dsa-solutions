#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q, c;
  cin >> n >> q >> c;
  vector<vector<vector<int>>> brightness(
      c + 1, vector<vector<int>>(101, vector<int>(101, 0)));
  int x, y, s;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> s;
    for (int timeMod = 0; timeMod <= c; timeMod++) {
      int starBrightness = (s + timeMod) % (c + 1);
      brightness[timeMod][x][y] += starBrightness;
    }
  }
  for (int time_mod = 0; time_mod <= c; time_mod++) {
    // First pass: row-wise prefix sum
    for (int i = 1; i <= 100; i++) {
      for (int j = 2; j <= 100; j++) {
        brightness[time_mod][i][j] += brightness[time_mod][i][j - 1];
      }
    }

    // Second pass: column-wise prefix sum
    for (int i = 2; i <= 100; i++) {
      for (int j = 1; j <= 100; j++) {
        brightness[time_mod][i][j] += brightness[time_mod][i - 1][j];
      }
    }
  }

  int t, x1, y1, x2, y2;
  for (int i = 0; i < q; i++) {
    cin >> t >> x1 >> y1 >> x2 >> y2;

    int time_mod = t % (c + 1);

    // Calculate rectangle sum using 2D prefix sum formula
    int result =
        brightness[time_mod][x2][y2] - brightness[time_mod][x1 - 1][y2] -
        brightness[time_mod][x2][y1 - 1] + brightness[time_mod][x1 - 1][y1 - 1];

    cout << result << "\n";
  }
}
