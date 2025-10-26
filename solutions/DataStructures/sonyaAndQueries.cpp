/*
 * Problem: Sonya and Queries
 * Link: https://codeforces.com/problemset/problem/713/A
 * Problem Statement: The user is given a series of queries. The queries can be of three types: add a number, delete a number, or count the numbers that match a given pattern. The pattern consists of '0's and '1's, where '0' represents an even digit and '1' represents an odd digit. An integer matches a pattern if the parity of its digits from right to left matches the pattern.
 * Approach: The solution converts each number into a binary string of length 18, where each character represents the parity of the corresponding digit. The string is padded with '0's to the left to ensure a fixed length. An unordered_map is used to store the frequency of each pattern. For '+' queries, the frequency of the corresponding pattern is incremented. For '-' queries, it's decremented. For '?' queries, the frequency of the given pattern is printed.
 * Time Complexity: The time complexity for each query is dominated by the `getPattern` function, which takes O(log10(x)) time, where x is the number. Since the numbers are up to 10^18, the number of digits is at most 18. So, the time complexity for each query is effectively O(1). For Q queries, the total time complexity is O(Q).
 * Space Complexity: The space complexity is O(Q * L), where Q is the number of queries and L is the maximum length of the pattern (18 in this case), as in the worst case, each query could be a '+' query with a unique pattern.
 */
#include <bits/stdc++.h>
using namespace std;

string getPattern(long long x) {
  string s = "";
  while (x > 0) {
    int d = x % 10;
    s += (d % 2 ? '1' : '0'); // odd → 1, even → 0
    x /= 10;
  }
  reverse(s.begin(), s.end());
  while (s.size() < 18)
    s = "0" + s; // pad to 18 digits
  return s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_map<string, long long> freq;
  int q;
  cin >> q;

  while (q--) {
    char op;
    long long x;
    string s;
    cin >> op;

    if (op == '+' || op == '-') {
      cin >> x;
      string p = getPattern(x);
      if (op == '+')
        freq[p]++;
      else
        freq[p]--;
    } else if (op == '?') {
      cin >> s;
      while (s.size() < 18)
        s = "0" + s; // pad left
      cout << freq[s] << "\n";
    }
  }

  return 0;
}
