/*
Problem: Permutation Sequence
Link: https://leetcode.com/problems/permutation-sequence/description/
Problem Statement: Given n and k, return the k-th permutation sequence. The set of numbers is [1, 2, ..., n].
Approach: The solution generates all possible permutations of the numbers from 1 to n and then returns the k-th permutation (0-indexed, so k-1). The `perms` function is a recursive helper that generates permutations using a backtracking approach. It uses `rotateRight` and `rotateLeft` helper functions to efficiently swap elements and backtrack. The `generateSet` function creates the initial string of numbers from 1 to n. Finally, `getPermutation` calls `generateSet` and `perms` to populate a vector with all permutations and then returns the element at index `k-1`.
Time Complexity: O(N! * N) - Generating all N! permutations, and each permutation involves string manipulations of length N.
Space Complexity: O(N!) - To store all N! permutations.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  void rotateRight(string &s, int start, int end) {
    char tmp = s[end];
    for (int i = end; i > start; --i)
      s[i] = s[i - 1];
    s[start] = tmp;
  }

  void rotateLeft(string &s, int start, int end) {
    char tmp = s[start];
    for (int i = start; i < end; ++i)
      s[i] = s[i + 1];
    s[end] = tmp;
  }

  void perms(string &set, int idx, vector<string> &result) {
    if (idx == set.size()) {
      result.push_back(set);
      return;
    }
    for (int j = idx; j < set.size(); ++j) {
      rotateRight(set, idx, j);
      perms(set, idx + 1, result);
      rotateLeft(set, idx, j);
    }
  }

  string generateSet(int n) {
    string result = "";
    for (int i = 1; i <= n; i++) {
      result += to_string(i);
    }
    return result;
  }

  string getPermutation(int n, int k) {
    vector<string> result;
    string set = generateSet(n);
    perms(set, 0, result);
    return result[k - 1];
  }
};

int main() {
  Solution sol;
  int n, k;
  cin >> n >> k;
  string permutation = sol.getPermutation(n, k);
  cout << permutation << endl;
  return 0;
}
