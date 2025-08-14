/*
 * Problem: 11085 - Back to the 8-Queens
 * Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2026
 * Problem Statement: Given a configuration of 8 queens on a chessboard, find the minimum number of moves to reach a state where no two queens attack each other.
 * Approach: The solution pre-computes all 92 valid 8-queens configurations using a recursive backtracking approach. For each input configuration, it then iterates through all pre-computed solutions, calculating the number of queens that need to be moved to match the solution. The minimum of these values is the answer.
 * Time Complexity: O(1) for each test case after pre-computation. The pre-computation takes O(8!) time.
 * Space Complexity: O(92 * 8) to store all possible solutions.
 */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> allSolutions;

bool isSafe(const vector<int> &board, int col, int row) {
  for (int c = 0; c < col; c++) {
    if (board[c] == row || abs(board[c] - row) == abs(c - col))
      return false; // same row or same diagonal
  }
  return true;
}

void generateSolutions(vector<int> &board, int col) {
  if (col == 8) {
    allSolutions.push_back(board);
    return;
  }
  for (int row = 1; row <= 8; row++) {
    if (isSafe(board, col, row)) {
      board[col] = row;
      generateSolutions(board, col + 1);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> board(8);
  generateSolutions(board, 0); // precompute all valid configurations

  int caseNum = 1;
  vector<int> input(8);
  while (true) {
    for (int i = 0; i < 8; i++) {
      if (!(cin >> input[i]))
        return 0; // EOF
    }

    int minMoves = INT_MAX;
    for (const auto &sol : allSolutions) {
      int moves = 0;
      for (int i = 0; i < 8; i++) {
        if (input[i] != sol[i])
          moves++;
      }
      minMoves = min(minMoves, moves);
    }

    cout << "Case " << caseNum++ << ": " << minMoves << "\n";
  }
}