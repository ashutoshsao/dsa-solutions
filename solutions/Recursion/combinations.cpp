/*
Problem: Combinations
Link: https://leetcode.com/problems/combinations/description/
Problem Statement: Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
Approach: The solution uses a recursive approach with backtracking. A helper function is used to build the combinations. The base case for the recursion is when the size of the temporary combination vector is equal to k. In the recursive step, we iterate from the current number to n, adding the number to the temporary combination and then recursively calling the helper function for the next number. After the recursive call returns, we backtrack by removing the number from the temporary combination.
Time Complexity: O(C(n, k) * k), where C(n, k) is the number of combinations.
Space Complexity: O(C(n, k) * k) to store the resulting combinations.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> temp;
    combineHelper(1, n, k, temp, ans);
    return ans;
  }

  void combineHelper(int start, int n, int k, vector<int> &temp,
                     vector<vector<int>> &ans) {
    if (temp.size() == k) {
      ans.push_back(temp);
      return;
    }

    for (int i = start; i <= n; ++i) {
      temp.push_back(i);
      combineHelper(i + 1, n, k, temp, ans);
      temp.pop_back(); // backtrack
    }
  }
};

int main() {
  Solution sol;
  int n = 4, k = 2;
  vector<vector<int>> result = sol.combine(n, k);

  cout << "Combinations of " << n << " choose " << k << ":\n";
  for (const auto &comb : result) {
    cout << "[";
    for (int i = 0; i < comb.size(); ++i) {
      cout << comb[i];
      if (i != comb.size() - 1)
        cout << ",";
    }
    cout << "]\n";
  }

  return 0;
}
