#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  void printAllCombs(vector<string> &result, string &tmp, int i, string &digits,
                     vector<string> &digitMap) {
    if (i == digits.size()) {
      result.push_back(tmp);
      return;
    }
    string letters = digitMap[digits[i] - '2'];
    for (char ch : letters) {
      tmp[i] = ch;
      printAllCombs(result, tmp, i + 1, digits, digitMap);
    }
  }

  vector<string> letterCombinations(string digits) {
    if (digits.empty())
      return {};

    vector<string> digitMap = {"abc", "def",  "ghi", "jkl",
                               "mno", "pqrs", "tuv", "wxyz"};

    vector<string> result;
    string tmp(digits.size(), ' '); // temp string with same size as digits
    printAllCombs(result, tmp, 0, digits, digitMap);
    return result;
  }
};

int main() {
  Solution sol;
  string input = "23";
  vector<string> result = sol.letterCombinations(input);

  for (const string &s : result) {
    cout << s << endl;
  }
  return 0;
}
