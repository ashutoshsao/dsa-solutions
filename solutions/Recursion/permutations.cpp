/*
 * Problem: Permutations
 * Link: https://leetcode.com/problems/permutations/description/
 * Problem Statement: Given an array of distinct integers, return all possible permutations.
 * Approach: The solution uses a recursive backtracking function, `getPerms`. It explores all possible swaps of elements in the array to generate permutations. The base case for the recursion is when the starting index `i` reaches the end of the array, at which point the current permutation is added to the result.
 * Time Complexity: O(n*n!), where n is the number of elements in the input array. There are n! permutations, and for each permutation, it takes O(n) time to copy it to the result vector.
 * Space Complexity: O(n) for the recursion depth. The result vector is not counted towards the space complexity.
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void getPerms(vector<int> &nums, int i, vector<vector<int>> &result) {
    if (i == nums.size()) {
      result.push_back(nums);
      return;
    }
    for (int j = i; j < nums.size(); j++) {
      swap(nums[i], nums[j]);
      getPerms(nums, i + 1, result);
      swap(nums[i], nums[j]);
    }
  }

  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    getPerms(nums, 0, result);
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 2, 3};

  vector<vector<int>> permutations = sol.permute(nums);

  cout << "All permutations:\n";
  for (const auto &perm : permutations) {
    cout << "[ ";
    for (int num : perm) {
      cout << num << " ";
    }
    cout << "]\n";
  }

  return 0;
}
