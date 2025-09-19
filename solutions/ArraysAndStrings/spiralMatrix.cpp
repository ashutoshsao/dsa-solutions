/*
Problem: Spiral Matrix
Link: https://leetcode.com/problems/spiral-matrix/
Problem Statement: Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
Approach: The solution uses four pointers to define the boundaries of the matrix: `top`, `bottom`, `left`, and `right`. It traverses the matrix in a spiral path by iterating through the top row from left to right, then the rightmost column from top to bottom, then the bottom row from right to left, and finally the leftmost column from bottom to top. After each traversal of a side, the corresponding boundary pointer is moved inward. The process continues until the `left` pointer crosses the `right` pointer or the `top` pointer crosses the `bottom` pointer.
Time Complexity: O(m*n), where m is the number of rows and n is the number of columns. Each element is visited once.
Space Complexity: O(1), as the traversal is done in-place and the output is printed to the console.
*/
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