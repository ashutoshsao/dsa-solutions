/*
Problem: Restore IP Addresses
Link: https://leetcode.com/problems/restore-ip-addresses/description/
Problem Statement: A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros. Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s.
Approach: The solution uses a recursive backtracking approach. A helper function `getIps` is defined to explore all possible ways of placing dots in the string. The function takes the current starting position in the string, the number of dots placed so far, the current path (the IP address being built), and a result vector. The base case for the recursion is when 4 dots have been placed and the entire string has been consumed. The function iterates through possible segment lengths (1, 2, or 3) and, if the segment is a valid IP address component, it makes a recursive call with the updated parameters.
Time Complexity: O(1)
Space Complexity: O(1)
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool isValid(const string &s) {
    if (s.empty() || s.size() > 3)
      return false;
    if (s[0] == '0' && s.size() > 1)
      return false;
    int num = stoi(s);
    return num >= 0 && num <= 255;
  }

  void getIps(string &s, int start, int dots, string path,
              vector<string> &result) {
    if (dots == 4 && start == s.length()) {
      path.pop_back(); // remove trailing dot
      result.push_back(path);
      return;
    }
    if (dots > 4)
      return;

    for (int len = 1; len <= 3; ++len) {
      if (start + len > s.length())
        break;
      string segment = s.substr(start, len);
      if (isValid(segment)) {
        getIps(s, start + len, dots + 1, path + segment + ".", result);
      }
    }
  }

  vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    if (s.length() < 4 || s.length() > 12)
      return result;
    getIps(s, 0, 0, "", result);
    return result;
  }
};

int main() {
  Solution sol;
  string input = "25525511135";
  vector<string> ips = sol.restoreIpAddresses(input);

  for (const string &ip : ips) {
    cout << ip << endl;
  }
}
