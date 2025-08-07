/*
Problem: Beautiful Arrangement
Link: https://leetcode.com/problems/beautiful-arrangement/description/
Problem Statement: Given an integer n, you need to find the count of all "beautiful arrangements". A beautiful arrangement is a permutation of the integers from 1 to n. This permutation, let's call it perm, must satisfy a specific condition for every position i from 1 to n. The condition is that for each i, either the number perm[i] is divisible by i, or i is divisible by perm[i]. The final output should be the total number of such permutations you can construct.
Approach: The solution uses a recursive backtracking approach. A helper function `allArrangements` is defined to explore all possible permutations. The function takes the current position `pos`, the integer `n`, and a `visited` vector to keep track of used numbers. The base case for the recursion is when `pos` exceeds `n`, at which point a valid arrangement has been found, and the count is incremented. In the recursive step, the function iterates through numbers from 1 to `n`. If a number has not been visited and satisfies the beautiful arrangement condition (either `pos` is divisible by `num` or `num` is divisible by `pos`), it is marked as visited, and the function is called recursively for the next position. After the recursive call returns, the number is marked as not visited to backtrack and explore other possibilities. The main function `countArrangement` initializes the `visited` vector and starts the recursion from the first position.
Time Complexity: O(n!)
Space Complexity: O(n)
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int count = 0;

  void allArrangements(int pos, int n, vector<bool> &visited) {
    if (pos > n) {
      count++;
      return;
    }
    for (int num = 1; num <= n; num++) {
      if (!visited[num] && (pos % num == 0 || num % pos == 0)) {
        visited[num] = true;
        allArrangements(pos + 1, n, visited);
        visited[num] = false;
      }
    }
  }

  int countArrangement(int n) {
    vector<bool> visited(n + 1, false);
    allArrangements(1, n, visited);
    return count;
  }
};

int main() {
  Solution sol;
  int n;
  cin >> n;
  int result = sol.countArrangement(n);
  cout << result << endl;
  return 0;
}
