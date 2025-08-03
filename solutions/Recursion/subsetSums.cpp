/*
Problem: Subset Sums
Link: https://www.geeksforgeeks.org/problems/subset-sums2234/1
Problem Statement: Given a list of integers, find the sum of all possible subsets.
Approach: The solution uses a recursive approach. A helper function is used to find the sums of all subsets. The base case for the recursion is when we have processed all the elements in the input array. At this point, the current sum is added to the result vector. In the recursive step, we have two choices for each element: either include it in the current subset and add it to the sum, or exclude it. We make two recursive calls to explore both possibilities.
Time Complexity: O(2^n), where n is the number of elements in the input array.
Space Complexity: O(2^n) for the result vector, and O(n) for the recursion stack.
*/
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
  public:
    void sumArr(int i, int sum, vector<int>& arr, vector<int>& result) {
        if (i == arr.size()) {
            result.push_back(sum);  // base case: one subset sum computed
            return;
        }

        // Include current element
        sumArr(i + 1, sum + arr[i], arr, result);

        // Exclude current element
        sumArr(i + 1, sum, arr, result);
    }

    vector<int> subsetSums(vector<int>& arr) {
        vector<int> result;
        sumArr(0, 0, arr, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 3};
    vector<int> res = sol.subsetSums(arr);

    for (int sum : res) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
