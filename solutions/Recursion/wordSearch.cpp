/*
Problem: Word Search
Link: https://leetcode.com/problems/word-search/
Problem Statement: Given an m x n grid of characters board and a string word, return true if word exists in the grid. The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
Approach: The solution uses a recursive backtracking approach. The main function iterates through each cell of the board and calls a helper function `matchCheck` to check if the word can be formed starting from that cell. The `matchCheck` function recursively explores the four adjacent cells (up, down, left, right) to find the next character in the word. To avoid reusing cells, the current cell's character is temporarily replaced with a special character ('#') and restored after the recursive calls.
Time Complexity: O(m * n * 4^l) where m is the number of rows, n is the number of columns, and l is the length of the word.
Space Complexity: O(l) for the recursion stack, where l is the length of the word.
*/
class Solution {
public:
  bool matchCheck(vector<vector<char>> &board, const string &word, int idx,
                  int x, int y) {
    if (idx == word.size())
      return true;
    int m = board.size();
    int n = board[0].size();

    if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != word[idx])
      return false;

    char temp = board[x][y];
    board[x][y] = '#';

    // explore in 4 directions
    bool found = matchCheck(board, word, idx + 1, x + 1, y) ||
                 matchCheck(board, word, idx + 1, x - 1, y) ||
                 matchCheck(board, word, idx + 1, x, y + 1) ||
                 matchCheck(board, word, idx + 1, x, y - 1);

    board[x][y] = temp; // restore original char
    return found;
  }

  bool exist(vector<vector<char>> &board, string word) {
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matchCheck(board, word, 0, i, j))
          return true;
      }
    }
    return false;
  }
};
