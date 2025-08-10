/*
Problem: Rat in a Maze
Link: https://www.codechef.com/problems/MM1803
Problem Statement: Given a square matrix of size N x N, where each cell can be either open (represented by 1) or blocked (represented by 0), a rat is placed at the source cell (0, 0). The rat wants to reach the destination cell at (N-1, N-1). The rat can move in four directions: Up (U), Down (D), Left (L), and Right (R). Find all possible paths that the rat can take to reach the destination from the source.
Approach: The problem is solved using a recursive backtracking algorithm. The main idea is to explore all possible paths from the source using Depth First Search (DFS). When the destination is reached, the current path is stored. If a path leads to a dead end or a blocked cell, the algorithm backtracks to the previous cell and explores other directions. To avoid visiting the same cell twice in a path, visited cells are marked and then unmarked during backtracking.
Time Complexity: O(4^(n*n))
Space Complexity: O(n*n)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValid(int row, int col, int n, vector<vector<bool>> &isVisited,
               const vector<vector<int>> &maze) {
    return row >= 0 && row < n && col >= 0 && col < n && maze[row][col] != 0 &&
           !isVisited[row][col];
  }

  void getPaths(int i, int j, int n, const vector<vector<int>> &maze,
                vector<vector<bool>> &isVisited, string &tmp,
                vector<string> &result) {
    if (i == n - 1 && j == n - 1) {
      result.push_back(tmp);
      return;
    }

    isVisited[i][j] = true;

    if (isValid(i + 1, j, n, isVisited, maze)) {
      tmp += "D";
      getPaths(i + 1, j, n, maze, isVisited, tmp, result);
      tmp.pop_back();
    }
    if (isValid(i, j - 1, n, isVisited, maze)) {
      tmp += "L";
      getPaths(i, j - 1, n, maze, isVisited, tmp, result);
      tmp.pop_back();
    }
    if (isValid(i, j + 1, n, isVisited, maze)) {
      tmp += "R";
      getPaths(i, j + 1, n, maze, isVisited, tmp, result);
      tmp.pop_back();
    }
    if (isValid(i - 1, j, n, isVisited, maze)) {
      tmp += "U";
      getPaths(i - 1, j, n, maze, isVisited, tmp, result);
      tmp.pop_back();
    }

    isVisited[i][j] = false;
  }

  vector<string> allPaths(const vector<vector<int>> &maze) {
    int n = maze.size();
    vector<string> result;

    if (maze[0][0] == 0) {
      return result;
    }

    string tmp = "";
    vector<vector<bool>> isVisited(n, vector<bool>(n, false));

    getPaths(0, 0, n, maze, isVisited, tmp, result);

    return result;
  }
};

int main() {

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> maze[i][j];
      }
    }

    Solution sol;
    vector<string> result = sol.allPaths(maze);
    for (const string &str : result) {
      cout << str << " ";
    }
    cout << "\n";
  }
  return 0;
}
