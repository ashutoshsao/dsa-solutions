/*
 * Problem: Grid Illumination
 * Link: https://leetcode.com/problems/grid-illumination/
 * Problem Statement: The user is given an n x n grid and a set of lamps. When a lamp is on, it illuminates its cell, its entire row, column, and both diagonals. For each query, the user needs to determine if the specified cell is illuminated. After each query, the lamp at the queried cell and its 8 adjacent lamps (if any) are turned off.
 * Approach: The solution uses hashmaps to keep track of the number of lamps illuminating each row, column, and diagonal. It also uses a set to store the positions of the lamps. For each query, it checks if the cell is illuminated by checking the hashmaps. Then, it turns off the lamps in the 3x3 area around the query by updating the hashmaps and the set of lamp positions.
 * Time Complexity: O(L + Q), where L is the number of lamps and Q is the number of queries.
 * Space Complexity: O(L), where L is the number of lamps.
 */
class Solution {
public:
  vector<int> gridIllumination(int n, vector<vector<int>> &lamps,
                               vector<vector<int>> &queries) {
    unordered_map<int, int> rowCount, colCount, diagCount, antiDiagCount;
    set<pair<int, int>> lampPositions;

    for (auto &lamp : lamps) {
      int r = lamp[0], c = lamp[1];
      if (lampPositions.insert({r, c})
              .second) { // Only if lamp wasn't already on
        rowCount[r]++;
        colCount[c]++;
        diagCount[r - c]++;     // major diagonal
        antiDiagCount[r + c]++; // minor diagonal
      }
    }

    vector<int> ans;
    int directions[9][2] = {{0, 0}, {-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                            {0, 1}, {1, -1},  {1, 0},  {1, 1}};

    for (auto &query : queries) {
      int r = query[0], c = query[1];

      // Check if cell is illuminated
      if (rowCount[r] > 0 || colCount[c] > 0 || diagCount[r - c] > 0 ||
          antiDiagCount[r + c] > 0) {
        ans.push_back(1);
      } else {
        ans.push_back(0);
      }

      // Turn off lamps in 3x3 area around query
      for (auto &dir : directions) {
        int nr = r + dir[0], nc = c + dir[1];
        if (lampPositions.count({nr, nc})) {
          lampPositions.erase({nr, nc});
          rowCount[nr]--;
          colCount[nc]--;
          diagCount[nr - nc]--;
          antiDiagCount[nr + nc]--;
        }
      }
    }

    return ans;
  }
};
