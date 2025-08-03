/*
Problem: Combination Sum
Link: https://leetcode.com/problems/combination-sum/description/
Problem Statement: Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order. The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
Approach: The solution uses a recursive approach with backtracking. A helper function is used to find the combinations. The base cases for the recursion are when the sum is less than 0 (in which case we return), when the sum is 0 (in which case we've found a valid combination and add it to the result), or when we've processed all the numbers. In the recursive step, we have two choices: either include the current number and recursively call the helper function with the same index (to allow for repetition), or exclude the current number and move to the next.
Time Complexity: O(N^(T/M + 1)), where N is the number of candidates, T is the target value, and M is the minimum value among the candidates.
Space Complexity: O(T/M) for the recursion stack.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void getSS(int sum, int i, vector<int> &tmp, vector<int>& nums, vector<vector<int>> &result) {
        if (sum < 0) return;

        if (sum == 0) {
            result.push_back(tmp);
            return;
        }

        if (i == nums.size()) return;

        // Include nums[i]
        tmp.push_back(nums[i]);
        getSS(sum - nums[i], i, tmp, nums, result); // allow repetition of same number
        tmp.pop_back(); // backtrack

        // Exclude nums[i]
        getSS(sum, i + 1, tmp, nums, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> tmp;
        getSS(target, 0, tmp, candidates, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> res = sol.combinationSum(candidates, target);

    for (const auto &comb : res) {
        for (int num : comb)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}
