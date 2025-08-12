/*
 * Problem: Rat in a Maze with Multiple Jumps
 * Link: https://www.geeksforgeeks.org/problems/rat-maze-with-multiple-jumps3852/1
 * Problem Statement: A rat is in a maze represented by an n*n matrix. The rat starts at the top-left (0,0) and must reach the bottom-right (n-1, n-1). It can only move forward or down. Each cell in the maze contains a number indicating the maximum number of steps the rat can jump from that cell; a zero indicates a dead end. The goal is to return a solution matrix where 1s mark the path taken, otherwise, return a matrix containing -1 if no path exists.
 * Approach: The solution uses backtracking. A recursive function `solveMaze` explores possible paths. It marks the current cell as part of the path and then tries to move right and down within the allowed jump distance. If a move leads to the destination, it returns true. If no path is found from the current cell, it backtracks by unmarking the cell and returns false.
 * Time Complexity: O(2^(n*n))
 * Space Complexity: O(n*n)
 */
class Solution {
public:
  bool solveMaze(int i, int j, vector<vector<int>> &path,
                 vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    if (i == m - 1 && j == n - 1) {
      path[i][j] = 1;
      return true;
    }

    path[i][j] = 1;

    int jump = matrix[i][j];

    for (int k = 1; k <= jump; k++) {
      // Move right
      if (j + k < n && solveMaze(i, j + k, path, matrix))
        return true;
      // Move down
      if (i + k < m && solveMaze(i + k, j, path, matrix))
        return true;
    }

    path[i][j] = 0;
    return false;
  }

  vector<vector<int>> ShortestDistance(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> path(m, vector<int>(n, 0));

    if (solveMaze(0, 0, path, matrix))
      return path;

    return {{-1}};
  }
};
