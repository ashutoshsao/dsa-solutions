/*
Problem: Unique Paths III
Link: https://leetcode.com/problems/unique-paths-iii/description/
Problem Statement: On a given grid, you must find the number of paths from a starting cell to an ending cell. The grid also contains empty, walkable squares and non-walkable obstacles. The key constraint is that the path must cover every single non-obstacle square exactly once. You can move in four directions: up, down, left, or right. The goal is to return the total count of these unique, all-encompassing paths.
Approach: The solution uses a backtracking approach. It explores all possible paths from the starting cell, keeping track of visited cells. The `countPaths` function recursively explores paths in all four directions. If the ending cell is reached and all empty cells have been visited, the path is counted.
Time Complexity: O(3^N), where N is the number of empty cells. In the worst case, we have to explore all possible paths. From each cell, we have at most 3 directions to go (since we can't go back).
Space Complexity: O(N), for the recursion stack, where N is the number of empty cells.
*/
class Solution {
private:
  const vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  bool isValid(int row, int col, const vector<vector<int>> &grid) {
    return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() &&
           grid[row][col] != -1;
  }

  int countPaths(int i, int j, int visitedCount, int targetCount,
                 const vector<vector<int>> &grid, vector<vector<bool>> &isVis) {
    if (grid[i][j] == 2) {
      return visitedCount == targetCount ? 1 : 0;
    }

    isVis[i][j] = true;
    int paths = 0;

    for (const auto &[dr, dc] : directions) {
      int newRow = i + dr, newCol = j + dc;
      if (isValid(newRow, newCol, grid) && !isVis[newRow][newCol]) {
        paths += countPaths(newRow, newCol, visitedCount + 1, targetCount, grid,
                            isVis);
      }
    }

    isVis[i][j] = false;
    return paths;
  }

public:
  int uniquePathsIII(vector<vector<int>> &grid) {
    int startRow = -1, startCol = -1, emptyCells = 0;

    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1) {
          startRow = i;
          startCol = j;
        }
        if (grid[i][j] != -1) {
          ++emptyCells;
        }
      }
    }

    vector<vector<bool>> visited(grid.size(),
                                 vector<bool>(grid[0].size(), false));
    return countPaths(startRow, startCol, 1, emptyCells, grid, visited);
  }
};
