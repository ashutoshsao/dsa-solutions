/*
Problem: Star Sky
Link: https://codeforces.com/problemset/problem/835/C
Problem Statement: You are given `n` stars. Each star is described by its coordinates (x, y) and its initial brightness `s`. The brightness of each star changes over time. At time `t`, the brightness of a star with initial brightness `s` becomes `(s + t) % (c + 1)`, where `c` is a given constant. You need to answer `q` queries. Each query consists of a time `t` and a rectangle defined by its bottom-left `(x1, y1)` and top-right `(x2, y2)` coordinates. For each query, you need to find the total brightness of all stars inside or on the border of the given rectangle at time `t`.
Approach: The solution uses a 3D prefix sum array `brightness[c+1][101][101]`. `brightness[time_mod][x][y]` stores the sum of brightness of all stars in the rectangle from (1,1) to (x,y) at a specific `time_mod`.
First, it pre-calculates the brightness of each star for each possible `time_mod` (from 0 to `c`).
Then, for each `time_mod`, it computes a 2D prefix sum array.
Finally, for each query, it calculates the `time_mod` for the given query time `t` and uses the pre-computed 2D prefix sums to find the sum of brightness in the given rectangle in O(1) time.
Time Complexity: O(c*MAX_X*MAX_Y + n*c + q), where `c` is the maximum initial brightness, `MAX_X` and `MAX_Y` are the maximum coordinates (100 in this case), `n` is the number of stars, and `q` is the number of queries.
Space Complexity: O(c*MAX_X*MAX_Y), for the 3D prefix sum array.
*/
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
