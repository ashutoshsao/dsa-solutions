/*
Problem: Sum of All Submatrices
Link: https://www.geeksforgeeks.org/sum-of-all-submatrices-of-a-given-matrix/
Problem Statement: Given a matrix of size N x M, find the sum of all possible submatrices.
Approach: The solution calculates the contribution of each element to the total sum. For an element at position `(i, j)` in an `N x M` matrix, it can be the top-left corner of `(i+1)*(j+1)` submatrices and the bottom-right corner of `(N-i)*(M-j)` submatrices. Therefore, each element `matrix[i][j]` contributes `matrix[i][j] * (i+1) * (j+1) * (N-i) * (M-j)` to the total sum. The algorithm iterates through all elements and sums up their contributions. The result is taken modulo 10^9 + 7.
Time Complexity: O(N*M), where N is the number of rows and M is the number of columns in the matrix.
Space Complexity: O(1).
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int mod = 1e9 + 7;
  int n, m;
  cin >> n >> m;

  vector<vector<int>> matrix(n, vector<int>(m));
  int *ptr = &matrix[0][0];

  // Taking inputs using pointer arithmetic which treats 2D array as 1D
  for (int i = 0; i < m * n; i++) {
    cin >> *(ptr + i);
  }

  long long sum = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      long long factor1 = (long long)(i + 1) * (n - i);
      long long factor2 = (long long)(j + 1) * (m - j);
      long long multiplier = (factor1 * factor2) % mod;
      long long contribution = multiplier * matrix[i][j];
      sum = (sum + contribution) % mod;
    }
  }

  cout << sum << endl;
  return 0;
}