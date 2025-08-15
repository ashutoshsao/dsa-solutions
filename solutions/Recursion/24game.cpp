/*
Problem: 24 Game
Link: https://leetcode.com/problems/24-game/description/
Problem Statement: You are given an array of four integers. You need to determine if it's possible to obtain the value 24 by using the four numbers and the operators +, -, *, and /.
Approach: The solution uses a recursive backtracking approach. It tries all possible combinations of two numbers from the list and performs all possible arithmetic operations (+, -, *, /) on them. The result of each operation replaces the two numbers in the list, and the function is called recursively with the smaller list. The base case for the recursion is when only one number is left in the list. If this number is 24 (within a small epsilon for floating-point precision), it returns true. If all possibilities are exhausted without reaching 24, it returns false.
Time Complexity: O(1), since the input size is fixed at 4. The number of permutations and combinations of numbers and operations is constant.
Space Complexity: O(1), as the recursion depth and the size of the lists at each step are bounded by the initial small input size.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  const double EPS = 1e-6;

public:
  bool judgePoint24(vector<int> &nums) {
    vector<double> a(nums.begin(), nums.end());
    return checkCards(a);
  }

private:
  bool checkCards(vector<double> &nums) {
    int n = nums.size();
    if (n == 1) {
      return fabs(nums[0] - 24.0) < EPS;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        vector<double> next;
        for (int k = 0; k < n; ++k) {
          if (k != i && k != j)
            next.push_back(nums[k]);
        }

        vector<double> possibilities = generate(nums[i], nums[j]);
        for (double val : possibilities) {
          next.push_back(val);
          if (checkCards(next))
            return true;
          next.pop_back();
        }
      }
    }
    return false;
  }

  vector<double> generate(double a, double b) {
    vector<double> res = {a + b, a - b, b - a, a * b};
    if (fabs(b) > EPS)
      res.push_back(a / b);
    if (fabs(a) > EPS)
      res.push_back(b / a);
    return res;
  }
};

int main() {
  Solution sol;
  vector<int> nums(4);
  for (int i = 0; i < 4; ++i)
    cin >> nums[i];

  cout << (sol.judgePoint24(nums) ? "true" : "false") << endl;
  return 0;
}
