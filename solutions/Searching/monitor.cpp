/*
 * Problem: Monitor
 * Link: https://codeforces.com/problemset/problem/846/D
 *
 * Problem Statement:
 * The problem asks to determine the earliest moment in time when an n x m monitor
 * becomes "broken". The monitor is considered broken if it contains a k x k
 * square composed entirely of non-functional pixels. You are given q pixels that
 * will eventually break, along with their coordinates (xi, yi) and the specific
 * time (ti) at which each pixel stops working.
 *
 * Approach:
 * The solution uses binary search on the time 't' to find the minimum time the
 * monitor becomes broken. For a given time 't', it checks if there is a k x k
 * subgrid of broken pixels. This check is done efficiently using a 2D prefix
 * sum array (also known as a summed-area table). The prefix sum array allows
 * calculating the sum of pixels in any rectangular subgrid in O(1) time, after
 * an O(n*m) preprocessing step. The overall approach is to first mark all
 * pixels that are broken at or before time 't', then build the prefix sum
 * array, and finally check all possible k x k subgrids.
 *
 * Time Complexity:
 * The time complexity is O(log(max_t) * n * m), where max_t is the maximum
 * possible time. The binary search takes O(log(max_t)) iterations, and in each
 * iteration, the isBroken function takes O(n*m) time to build the prefix sums
 * and check all submatrices.
 *
 * Space Complexity:
 * The space complexity is O(n*m) for storing the grid and the prefix sum array.
 */
#include <bits/stdc++.h>
using namespace std;

struct Pixel {
  int x, y, t;
};

int n, m, k, q;

// Check if monitor is broken at time T (no extra padding arrays)
bool isBroken(int T, const vector<Pixel> &points) {
  static int grid[505][505];
  static int pref[505][505];

  // Reset grid
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      grid[i][j] = 0;

  // Mark broken pixels (t <= T)
  for (auto &p : points)
    if (p.t <= T)
      grid[p.x][p.y] = 1;

  // Build prefix sums (fully 0-indexed)
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int sum = grid[i][j];
      if (i > 0)
        sum += pref[i - 1][j];
      if (j > 0)
        sum += pref[i][j - 1];
      if (i > 0 && j > 0)
        sum -= pref[i - 1][j - 1];
      pref[i][j] = sum;
    }
  }

  // Check all k×k submatrices
  for (int i = 0; i + k - 1 < n; i++) {
    for (int j = 0; j + k - 1 < m; j++) {
      int x2 = i + k - 1, y2 = j + k - 1;
      int sum = pref[x2][y2];
      if (i > 0)
        sum -= pref[i - 1][y2];
      if (j > 0)
        sum -= pref[x2][j - 1];
      if (i > 0 && j > 0)
        sum += pref[i - 1][j - 1];
      if (sum == k * k)
        return true; // Found full broken k×k block
    }
  }

  return false;
}

int main() {
  cin >> n >> m >> k >> q;
  vector<Pixel> points(q);

  int minT = INT_MAX, maxT = INT_MIN;
  for (int i = 0; i < q; i++) {
    cin >> points[i].x >> points[i].y >> points[i].t;
    // Convert to 0-indexed
    points[i].x--;
    points[i].y--;
    minT = min(minT, points[i].t);
    maxT = max(maxT, points[i].t);
  }

  sort(points.begin(), points.end(),
       [](const Pixel &a, const Pixel &b) { return a.t < b.t; });

  int left = minT, right = maxT, ans = -1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (isBroken(mid, points)) {
      ans = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  cout << ans << '\n';
  return 0;
}
