/*
 * Problem: 263A - Beautiful Matrix
 * Link: https://codeforces.com/problemset/problem/263/A
 * Problem Statement: You are given a 5x5 matrix containing 24 zeroes and a single one. The goal is to make the matrix beautiful, which means the '1' must be in the center of the matrix (at position (3, 3)). In one move, you can swap two adjacent rows or two adjacent columns. Find the minimum number of moves required.
 * Approach: The number of moves required is the Manhattan distance between the current position of the '1' and the center (3, 3). The Manhattan distance between two points (r1, c1) and (r2, c2) is |r1 - r2| + |c1 - c2|. We first find the coordinates of the '1', and then calculate the Manhattan distance to (3, 3).
 * Time Complexity: O(1), since the matrix size is fixed at 5x5.
 * Space Complexity: O(1).
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<vector<int>> mat(6, vector<int>(6));

  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {
      cin >> mat[i][j];
    }
  }

  int r, c;
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {
      if (mat[i][j] == 1) {
        r = i;
        c = j;
      }
    }
  }

  int ans = abs(c - 3) + abs(r - 3);

  cout << ans << "\n";

  return 0;
}
