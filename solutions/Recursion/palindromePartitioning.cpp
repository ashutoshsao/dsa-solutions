/*
Problem: Palindrome Partitioning
Link: https://leetcode.com/problems/palindrome-partitioning/description/
Problem Statement: Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
Approach: The solution uses a recursive approach to find all possible palindrome partitions of the input string. The `allPartitions` function explores all possible partitions starting from a given index. For each substring starting from the current index, it checks if the substring is a palindrome. If it is, the substring is added to the current partition, and the function is called recursively for the remaining part of the string. After the recursive call returns, the added substring is removed (backtracking) to explore other possibilities. The `isPalindrome` function is a helper function that checks if a given string is a palindrome by comparing characters from both ends.
Time Complexity: O(n * 2^n)
Space Complexity: O(n)
*/
class Solution {
private:
  bool isPalindrome(const string &s, int left, int right) {
    while (left < right) {
      if (s[left] != s[right]) {
        return false;
      }
      left++;
      right--;
    }
    return true;
  }

  void allPartitions(const string &s, int start, vector<string> &part,
                     vector<vector<string>> &result) {
    if (start == s.length()) {
      result.push_back(part);
      return;
    }

    for (int end = start; end < s.length(); end++) {
      if (isPalindrome(s, start, end)) {
        part.push_back(s.substr(start, end - start + 1));
        allPartitions(s, end + 1, part, result);
        part.pop_back();
      }
    }
  }

public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> part;
    allPartitions(s, 0, part, result);
    return result;
  }
};
