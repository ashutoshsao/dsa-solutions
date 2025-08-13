/*
Problem: N-Queens
Link: https://leetcode.com/problems/n-queens/
Problem Statement: The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other. Given an integer n, return all distinct solutions to the n-queens puzzle.
Approach: The solution uses backtracking. We try to place a queen in each row, one by one. For each row, we iterate through all the columns and check if it's safe to place a queen at the current position. A position is safe if it's not attacked by any other queen placed in the previous rows. After placing a queen, we recursively call the function for the next row. If we reach the end of the board, we have found a valid solution. We then backtrack and try other possibilities.
Time Complexity: O(N!)
Space Complexity: O(N^2)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  bool isSafe(int i, int j, vector<string> &tmp) {
    int x = i - 1;
    // check column
    while (x >= 0) {
      if (tmp[x][j] == 'Q')
        return false;
      x--;
    }
    // check upper-left diagonal
    x = i - 1;
    int y = j - 1;
    while (x >= 0 && y >= 0) {
      if (tmp[x][y] == 'Q')
        return false;
      x--;
      y--;
    }
    // check upper-right diagonal
    x = i - 1;
    y = j + 1;
    while (x >= 0 && y < tmp.size()) {
      if (tmp[x][y] == 'Q')
        return false;
      x--;
      y++;
    }
    return true;
  }

  void findNQ(int i, int n, vector<string> &tmp,
              vector<vector<string>> &result) {
    if (i == n) {
      result.push_back(tmp);
      return;
    }
    for (int c = 0; c < n; c++) {
      if (isSafe(i, c, tmp)) {
        tmp[i][c] = 'Q';
        findNQ(i + 1, n, tmp, result);
        tmp[i][c] = '.';
      }
    }
  }

public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> tmp(n, string(n, '.'));
    findNQ(0, n, tmp, result);
    return result;
  }
};

int main() {
  int n;
  cin >> n;

  Solution sol;
  vector<vector<string>> solutions = sol.solveNQueens(n);

  cout << "Number of solutions: " << solutions.size() << "\n";
  for (int idx = 0; idx < solutions.size(); idx++) {
    cout << "Solution " << idx + 1 << ":\n";
    for (string row : solutions[idx]) {
      cout << row << "\n";
    }
    cout << "\n";
  }

  return 0;
}
