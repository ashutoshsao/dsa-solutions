
/*
 * Problem: Sum of Manhattan distances between all pairs of points
 * Link: https://www.geeksforgeeks.org/sum-manhattan-distances-pairs-points/
 * Problem Statement: Given n integer coordinates, find the sum of the Manhattan distance between all pairs of coordinates.
 * The Manhattan Distance between two points (x1, y1) and (x2, y2) is defined as: |x1 - x2| + |y1 - y2|.
 * Approach: The sum of Manhattan distances can be decomposed into the sum of absolute differences of x-coordinates and the sum of absolute differences of y-coordinates.
 * For a 1D array of coordinates, the sum of all pairwise differences can be calculated efficiently in O(n log n) time.
 * First, sort the coordinates. Then, for each coordinate p[i], its contribution to the total sum of differences is i * p[i] - (p[0] + p[1] + ... + p[i-1]).
 * A prefix sum can be used to calculate this efficiently. The C++ solution uses a suffix sum trick which is equivalent.
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  const long long MOD = 1e9 + 7;
  int n;
  cin >> n;

  vector<long long> xPoints(n), yPoints(n);
  long long xSum = 0, ySum = 0;

  for (int i = 0; i < n; i++) {
    cin >> xPoints[i] >> yPoints[i];
    xSum += xPoints[i];
    ySum += yPoints[i];
  }

  sort(xPoints.begin(), xPoints.end());
  sort(yPoints.begin(), yPoints.end());

  long long xDiff = 0, yDiff = 0;

  for (int i = 0; i < n; i++) {
    xSum -= xPoints[i]; // suffix sum trick
    long long contrib = xSum - 1LL * (n - 1 - i) * xPoints[i];
    xDiff = (xDiff + contrib) % MOD;
    if (xDiff < 0)
      xDiff += MOD;
  }

  for (int i = 0; i < n; i++) {
    ySum -= yPoints[i]; // suffix sum trick
    long long contrib = ySum - 1LL * (n - 1 - i) * yPoints[i];
    yDiff = (yDiff + contrib) % MOD;
    if (yDiff < 0)
      yDiff += MOD;
  }

  long long total = (xDiff + yDiff) % MOD;
  cout << total << "\n";
}
