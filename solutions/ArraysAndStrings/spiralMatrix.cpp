// program to print matrix elemtnets in spiral traversal
#include <bits/stdc++.h>
using namespace std;

int main() {
  int m, n;
  cin >> m >> n;

  vector<vector<int>> matrix(m, vector<int>(n));

  // Take input
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  int top = 0, bottom = m - 1;
  int left = 0, right = n - 1;

  while (top <= bottom && left <= right) {
    // Left to Right
    for (int j = left; j <= right; j++) {
      cout << matrix[top][j] << " ";
    }
    top++;

    // Top to Bottom
    for (int i = top; i <= bottom; i++) {
      cout << matrix[i][right] << " ";
    }
    right--;

    // Right to Left
    if (top <= bottom) {
      for (int j = right; j >= left; j--) {
        cout << matrix[bottom][j] << " ";
      }
      bottom--;
    }

    // Bottom to Top
    if (left <= right) {
      for (int i = bottom; i >= top; i--) {
        cout << matrix[i][left] << " ";
      }
      left++;
    }
  }

  return 0;
}
