/*
Problem: Permutations II
Link: https://leetcode.com/problems/permutations-ii/description/
Problem Statement: Given a collection of numbers that may contain duplicates, the task is to return all possible unique permutations.
Approach: The solution uses a recursive backtracking approach to generate unique permutations. The `genPermute` function is a helper function that takes the `nums` vector, the current index `i`, and the `result` vector of permutations. The base case for the recursion is when `i` reaches the last element of the `nums` vector, meaning a complete permutation has been formed, which is then added to the `result`. To handle duplicates and ensure unique permutations, an `unordered_set` named `freq` is used within the loop. This set keeps track of numbers that have already been used at the current position `i` to avoid generating duplicate permutations. In the loop, for each element from `i` to `nums.size() - 1`, if the element has not been seen before at this position (checked using `freq.count`), it's added to `freq`. Then, the current element `nums[i]` is swapped with `nums[j]`. The `genPermute` function is called recursively for the next position `i + 1`. After the recursive call returns, the swap is undone (backtracking) to restore the array to its previous state for exploring other possibilities. The `permuteUnique` function initializes the `result` vector and calls `genPermute` starting from index 0.
Time Complexity: O(N * N!) where N is the number of elements in `nums`. In the worst case, if all elements are unique, it's O(N!). The N factor comes from the loop and swap operations.
Space Complexity: O(N) for the recursion stack depth and the `unordered_set`.
*/
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  void genPermute(vector<int> &nums, int i, vector<vector<int>> &result) {
    if (i == nums.size() - 1) {
      result.push_back(nums);
      return;
    }

    unordered_set<int> freq;
    for (int j = i; j < nums.size(); j++) {
      if (freq.count(nums[j]))
        continue;
      freq.insert(nums[j]);

      swap(nums[i], nums[j]);
      genPermute(nums, i + 1, result);
      swap(nums[i], nums[j]); // backtrack
    }
  }

  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> result;
    genPermute(nums, 0, result);
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 1, 2};

  vector<vector<int>> permutations = sol.permuteUnique(nums);

  cout << "Unique permutations:\n";
  for (const auto &perm : permutations) {
    for (int num : perm) {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}
