/*
Problem: Combination Sum III
Link: https://leetcode.com/problems/combination-sum-iii/description/
Problem Statement: Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
- Only numbers from 1 to 9 are used.
- Each number is used at most once.
Return a list of all possible valid combinations.
Approach: The solution uses a recursive approach with backtracking. A helper function is used to find the combinations. The base case for the recursion is when k is 0 and n is 0, at which point the current combination is added to the result. In the recursive step, we iterate from the current number to 9. If the current number is greater than the remaining sum, we prune the recursion. Otherwise, we add the number to the current combination and recursively call the helper function with updated parameters. After the recursive call, we backtrack by removing the number from the current combination.
Time Complexity: O(C(9, k) * k), where C(9, k) is the number of combinations.
Space Complexity: O(k) for the recursion stack and the temporary combination vector.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> current;
    getSS(1, k, n, current, result);
    return result;
  }

private:
  void getSS(int start, int k, int n, vector<int> &current,
             vector<vector<int>> &result) {
    if (k == 0 && n == 0) {
      result.push_back(current);
      return;
    }

    for (int i = start; i <= 9; i++) {
      if (i > n)
        break; // Prune the recursion if current number exceeds remaining sum

      current.push_back(i);
      getSS(i + 1, k - 1, n - i, current, result);
      current.pop_back(); // Backtrack
    }
  }
};

int main() {
  Solution sol;
  int k = 3, n = 9;
  vector<vector<int>> res = sol.combinationSum3(k, n);

  for (const auto &comb : res) {
    for (int num : comb)
      cout << num << " ";
    cout << endl;
  }
  return 0;
}
