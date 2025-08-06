/*
Problem: The k-th Lexicographical String of All Happy Strings of Length n
Link:
https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/
Problem Statement: A happy string is a string that:
- consists only of letters of the set ['a', 'b', 'c'].
- s[i] != s[i+1] for all i from 0 to s.length - 2 (string is 1-indexed).
Given two integers n and k, return the k-th lexicographical string among all
happy strings of length n. If there are less than k happy strings of length n,
return an empty string. Approach: The solution uses a recursive approach to
generate all happy strings of length n. A helper function `getStrings` is used
to build the strings. The function is called recursively, and at each step, it
appends a character from the set {'a', 'b', 'c'} that is different from the last
character of the current string. When a string of length n is formed, it is
added to a result vector. Finally, the k-th string from the sorted list of happy
strings is returned. Time Complexity: O(3 * 2^(n-1)) which is O(2^n) because for
the first character we have 3 choices and for the rest n-1 characters, we have 2
choices. Space Complexity: O(k) where k is the number of happy strings, to store
the result vector.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  void getStrings(int pos, string &tmp, const string &set,
                  vector<string> &result, int n) {
    if (pos == n) {
      result.push_back(tmp);
      return;
    }

    for (int j = 0; j < set.length(); j++) {
      if (tmp.empty() || tmp.back() != set[j]) {
        tmp.push_back(set[j]);
        getStrings(pos + 1, tmp, set, result, n);
        tmp.pop_back();
      }
    }
  }

  int getNoOfSets(int n, int s) {
    if (n == 0)
      return 0;
    int count = s;
    for (int i = 1; i < n; i++) {
      count *= (s - 1);
    }
    return count;
  }

  string getHappyString(int n, int k) {
    string set = "abc";
    int total = getNoOfSets(n, set.size());
    if (k > total)
      return "";
    vector<string> result;
    string tmp;
    getStrings(0, tmp, set, result, n);
    return result[k - 1];
  }
};

int main() {
  Solution sol;
  int n = 3;
  int k = 9;
  string happyString = sol.getHappyString(n, k);
  cout << happyString << endl;
  return 0;
}
