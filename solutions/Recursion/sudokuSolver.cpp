/*
Problem: Sudoku Solver
Link: https://leetcode.com/problems/sudoku-solver/
Problem Statement: Write a program to solve a Sudoku puzzle by filling the empty cells. A sudoku solution must satisfy all of the following rules:
1. Each of the digits 1-9 must occur exactly once in each row.
2. Each of the digits 1-9 must occur exactly once in each column.
3. Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
Approach: The solution uses backtracking. We traverse the Sudoku grid, and for each empty cell, we try to place a digit from 1 to 9. We check if the current digit is valid by checking if it already exists in the same row, column, or 3x3 subgrid. If the digit is valid, we place it and recursively call the function for the next empty cell. If the recursive call returns true, it means a solution is found. If not, we backtrack and try the next digit.
Time Complexity: O(9^(N*N))
Space Complexity: O(N*N)
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  void getsudoku(int i, int j, bool &ansFound, int n,
                 vector<vector<int>> &rowFreq, vector<vector<int>> &colFreq,
                 vector<vector<int>> &mFreq, vector<vector<char>> &tmp,
                 vector<vector<char>> &board) {
    if (ansFound)
      return;
    if (i == n) {
      // Copy solution back to board
      for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
          board[r][c] = tmp[r][c];
        }
      }
      ansFound = true;
      return;
    }
    if (board[i][j] != '.') {
      if (j < n - 1)
        getsudoku(i, j + 1, ansFound, n, rowFreq, colFreq, mFreq, tmp, board);
      else
        getsudoku(i + 1, 0, ansFound, n, rowFreq, colFreq, mFreq, tmp, board);
      return;
    }
    int matNum = (i / 3) * 3 + (j / 3);
    for (int val = 1; val <= n; val++) {
      if (rowFreq[i][val - 1] == 0 && colFreq[j][val - 1] == 0 &&
          mFreq[matNum][val - 1] == 0) {
        // DO
        tmp[i][j] = val + '0';
        rowFreq[i][val - 1] = colFreq[j][val - 1] = mFreq[matNum][val - 1] = 1;

        // Recurse
        if (j < n - 1)
          getsudoku(i, j + 1, ansFound, n, rowFreq, colFreq, mFreq, tmp, board);
        else
          getsudoku(i + 1, 0, ansFound, n, rowFreq, colFreq, mFreq, tmp, board);

        // UNDO
        tmp[i][j] = '.';
        rowFreq[i][val - 1] = colFreq[j][val - 1] = mFreq[matNum][val - 1] = 0;
      }
    }
  }

public:
  void solveSudoku(vector<vector<char>> &board) {
    bool ansFound = false;
    int n = board.size(); // Square matrix size (9 for Sudoku)
    vector<vector<int>> rowFreq(n, vector<int>(n, 0));
    vector<vector<int>> colFreq(n, vector<int>(n, 0));
    vector<vector<int>> mFreq(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        char val = board[i][j];
        if (val != '.') {
          int idx = val - '1';
          rowFreq[i][idx]++;
          colFreq[j][idx]++;
          int subIndex = (i / 3) * 3 + (j / 3);
          mFreq[subIndex][idx]++;
        }
      }
    }
    vector<vector<char>> tmp = board;
    getsudoku(0, 0, ansFound, n, rowFreq, colFreq, mFreq, tmp, board);
  }
};

void printBoard(const vector<vector<char>> &board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j] << ' ';
    }
    cout << '\n';
  }
}

int main() {
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  Solution solver;
  cout << "Original Sudoku:\n";
  printBoard(board);

  solver.solveSudoku(board);

  cout << "\nSolved Sudoku:\n";
  printBoard(board);

  return 0;
}
