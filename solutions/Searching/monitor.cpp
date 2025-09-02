/*
Problem: D. Monitor
Link: https://codeforces.com/problemset/problem/846/D
Problem Statement: A monitor is represented by an n x m grid. The monitor is considered "broken" as soon as a k x k square consists entirely of broken pixels. You are given the dimensions n, m, the square size k, and a list of q pixels that will break. For each of these q pixels, you are given its coordinates (x, y) and the time t at which it breaks. The goal is to find the earliest moment in time when a k x k square of broken pixels is formed. If no such square is formed even after all q pixels have broken, you should report -1.
Approach: The solution uses binary search on the time t. For a given time t, we can determine if a k x k square of broken pixels exists. This is done by creating a 2D prefix sum array. For a given time t, a cell is considered "good" (value 1) if its breaking time is less than or equal to t, and "bad" (value 0) otherwise. The prefix sum array helps to quickly calculate the sum of any k x k subgrid. If the sum of any k x k subgrid is equal to k*k, it means all pixels in that subgrid are broken, and the monitor is broken at time t. The binary search finds the minimum t for which this condition is met.
Time Complexity: O(q + n * m * log(maxT)), where maxT is the maximum breaking time. The isBroken function takes O(n*m) and it is called log(maxT) times.
Space Complexity: O(n*m) for the matrix and prefix sum array.
*/
#include <bits/stdc++.h>
using namespace std;

bool isBroken(vector<vector<int>> &matrix, int T, int k) {
  int n = matrix.size(), m = matrix[0].size();
  vector<vector<int>> good(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      good[i][j] = (matrix[i][j] <= T) ? 1 : 0;
    }
  }
  vector<vector<int>> pref(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      pref[i][j] = good[i][j];
      if (i > 0)
        pref[i][j] += pref[i - 1][j];
      if (j > 0)
        pref[i][j] += pref[i][j - 1];
      if (i > 0 && j > 0)
        pref[i][j] -= pref[i - 1][j - 1];
    }
  }

  // check all k×k blocks
  for (int i = k - 1; i < n; i++) {
    for (int j = k - 1; j < m; j++) {
      int x1 = i - k + 1, y1 = j - k + 1;
      int sum = pref[i][j];
      if (x1 > 0)
        sum -= pref[x1 - 1][j];
      if (y1 > 0)
        sum -= pref[i][y1 - 1];
      if (x1 > 0 && y1 > 0)
        sum += pref[x1 - 1][y1 - 1];

      if (sum == k * k)
        return true; // found a valid working block
    }
  }
  return false;
}

int main() {
  int n, m, k, q;
  cin >> n >> m >> k >> q;
  // define matrix
  vector<vector<int>> matrix(n, vector<int>(m, INT_MAX));

  int maxT = 0;
  for (int i = 0; i < q; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    --x;
    --y; // convert to 0-based indexing
    matrix[x][y] = t;
    maxT = max(maxT, t);
  }

  int l = 0, h = maxT, ans = -1;
  while (l <= h) {
    int m = l + (h - l) / 2;
    bool r = isBroken(matrix, m, k);
    if (!r)
      l = m + 1;
    else {
      ans = m;
      h = m - 1;
    }
  }
  cout << ans << "\n";
}
