/*
* Problem: DZY Loves Chessboard
* Link: https://codeforces.com/problemset/problem/445/A
* Problem Statement: You are given a chessboard of size n x m. Some cells are marked as good ('.') and others as bad ('-'). You need to place chessmen on the good cells such that no two adjacent (sharing a side) cells have the same color. The colors of the chessmen are Black ('B') and White ('W').
* Approach: Iterate through the chessboard. For each good cell ('.'), determine its color based on its coordinates (i, j). If (i + j) is even, place a 'W' (White); otherwise, place a 'B' (Black). This ensures a valid checkerboard pattern where no two adjacent cells have the same color. Bad cells ('-') remain unchanged.
* Time Complexity: O(n*m)
* Space Complexity: O(n*m) for storing the board
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == '.') {
        if ((i + j) % 2 == 0) {
          arr[i][j] = 'W';
        } else {
          arr[i][j] = 'B';
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << "\n";
  }
}
