/*
Problem: Rotate Image
Link: https://leetcode.com/problems/rotate-image/
Problem Statement: You are given an n x n 2D matrix representing an image. Rotate the image by 90 degrees (clockwise). You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
Approach: The solution uses a two-step process to rotate the image in-place.
1. Transpose the matrix: It iterates through the matrix and swaps the elements `matrix[i][j]` with `matrix[j][i]`.
2. Reverse each row: After transposing, it iterates through each row of the matrix and reverses it.
This combination of transposing and reversing results in a 90-degree clockwise rotation.
Time Complexity: O(n*n), as it iterates through the matrix twice.
Space Complexity: O(1), as the rotation is done in-place.
*/
// program to rotate matrix 90 degrees (clockwise), reverse colomn wise to
// rotate (anticlock)
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<int>> twodv(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> twodv[i][j];
    }
  }
  int temp;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (i != j) {
        temp = twodv[i][j];
        twodv[i][j] = twodv[j][i];
        twodv[j][i] = temp;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    reverse(twodv[i].begin(), twodv[i].end());
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << twodv[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}