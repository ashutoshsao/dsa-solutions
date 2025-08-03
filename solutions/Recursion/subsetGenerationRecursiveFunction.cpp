// program to create a powersetarray using recursive function
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void printAllSubsets(vector<int> &nums, int n, int i, vector<int> &tmp, int s,
                       vector<vector<int>> &result) {
    if (i == n) {
      // Push only elements from tmp[0] to tmp[s-1]
      vector<int> subset;
      for (int j = 0; j < s; ++j) {
        subset.push_back(tmp[j]);
      }
      result.push_back(subset);
      return;
    }

    // Include nums[i] first
    tmp[s] = nums[i];
    printAllSubsets(nums, n, i + 1, tmp, s + 1, result);

    // Then exclude nums[i]
    printAllSubsets(nums, n, i + 1, tmp, s, result);
  }

  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result;
    int n = nums.size();
    vector<int> tmp(n); // Temporary buffer of size n
    printAllSubsets(nums, n, 0, tmp, 0, result);
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> res = sol.subsets(nums);

  cout << "Subsets:\n";
  for (const auto &subset : res) {
    cout << "[ ";
    for (int num : subset) {
      cout << num << " ";
    }
    cout << "]\n";
  }

  return 0;
}
