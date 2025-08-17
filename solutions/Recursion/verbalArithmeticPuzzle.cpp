/*
 * Problem: Verbal Arithmetic Puzzle
 * Link: https://leetcode.com/problems/verbal-arithmetic-puzzle/description/
 * Problem Statement: Given an equation, represented by words on the left side and the result on the right side. You need to check if the equation is solvable under the following rules:
 *   - Each character is decoded as one digit (0 - 9).
 *   - No two characters can map to the same digit.
 *   - Each words[i] and result are decoded as one number without leading zeros.
 *   - Sum of numbers on the left side (words) will equal to the number on the right side (result).
 * Approach: The solution uses a backtracking algorithm to explore all possible assignments of digits to characters. It processes the equation column by column from right to left. For each character, it tries to assign an unused digit, ensuring that leading characters of words are not assigned '0'. If an assignment leads to a valid solution, it returns true. If all possibilities are exhausted without finding a solution, it backtracks and tries a different assignment.
 * Time Complexity: O(10!)
 * Space Complexity: O(C), where C is the number of unique characters.
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isSolvable(vector<string> &words, string result) {
    unordered_map<char, int> charToDigit;
    vector<bool> used(10, false);
    unordered_set<char> leadingChars;

    // Add result to words for processing early
    words.push_back(result);

    // Mark characters that cannot be 0 (leading characters)
    for (const string &word : words) {
      if (word.length() > 1) {
        leadingChars.insert(word[0]);
      }
    }

    // Find maximum length for column processing
    int maxLen = 0;
    for (const string &word : words) {
      maxLen = max(maxLen, (int)word.length());
    }

    return backtrack(words, 0, 0, 0, maxLen, charToDigit, used, leadingChars);
  }

private:
  bool backtrack(vector<string> &words, int col, int row, int carry, int maxLen,
                 unordered_map<char, int> &charToDigit, vector<bool> &used,
                 const unordered_set<char> &leadingChars) {

    int n = words.size();

    // Processed all columns - check if no remaining carry
    if (col == maxLen) {
      return carry == 0;
    }

    // Processed all rows in current column
    if (row == n) {
      return carry % 10 == 0 && backtrack(words, col + 1, 0, carry / 10, maxLen,
                                          charToDigit, used, leadingChars);
    }

    string &word = words[row];

    // Skip if word doesn't have character at this column
    if (col >= word.length()) {
      return backtrack(words, col, row + 1, carry, maxLen, charToDigit, used,
                       leadingChars);
    }

    // Get character (process from right to left)
    char ch = word[word.length() - 1 - col];

    // Result word is subtracted, others are added
    int sign = (row == n - 1) ? -1 : 1;

    // If character already has digit assigned
    if (charToDigit.count(ch)) {
      return backtrack(words, col, row + 1, carry + sign * charToDigit[ch],
                       maxLen, charToDigit, used, leadingChars);
    }

    // Try assigning each unused digit
    for (int digit = 0; digit <= 9; digit++) {
      if (used[digit])
        continue;

      // Cannot assign 0 to leading character
      if (digit == 0 && leadingChars.count(ch))
        continue;

      // DO
      charToDigit[ch] = digit;
      used[digit] = true;

      // RECURSE
      if (backtrack(words, col, row + 1, carry + sign * digit, maxLen,
                    charToDigit, used, leadingChars)) {
        return true;
      }

      // UNDO
      charToDigit.erase(ch);
      used[digit] = false;
    }

    return false;
  }
};

int main() {
  Solution sol;

  vector<string> words1 = {"SEND", "MORE"};
  string result1 = "MONEY";
  cout << (sol.isSolvable(words1, result1) ? "true" : "false") << endl;

  vector<string> words2 = {"SIX", "SEVEN", "SEVEN"};
  string result2 = "TWENTY";
  cout << (sol.isSolvable(words2, result2) ? "true" : "false") << endl;

  vector<string> words3 = {"LEET", "CODE"};
  string result3 = "POINT";
  cout << (sol.isSolvable(words3, result3) ? "true" : "false") << endl;

  return 0;
}