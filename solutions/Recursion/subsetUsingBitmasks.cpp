// program to create a powersetarray using bitmasking
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    int n = nums.size();
    int total = pow(2, n);
    vector<vector<int>> result;

    for (int i = 0; i < total; i++) {
      vector<int> sub;
      int temp = i;
      for (int j = 0; j < n; j++) {
        if (temp % 2 == 1) {
          sub.push_back(nums[j]);
        }
        temp /= 2;
      }
      result.push_back(sub);
    }
    return result;
  }
};

int main() {
  vector<int> nums = {1, 2, 3};
  Solution sol;
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
