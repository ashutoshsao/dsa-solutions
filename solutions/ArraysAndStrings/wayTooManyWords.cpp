/*
Problem: Way Too Long Words
Link: https://codeforces.com/problemset/problem/71/A
Problem Statement: A word is considered too long if its length is strictly greater than 10. When a word is too long, it is replaced with a special abbreviation. This abbreviation is made by taking the first letter of the word, then the number of letters between the first and last letters, and finally the last letter of the word. For example, "localization" would be "l10n".
Approach: The solution reads each word. If the length of the word is greater than 10, it constructs the abbreviation by taking the first character, converting the length minus 2 to a string, and appending the last character. Otherwise, it prints the word as is.
Time Complexity: O(L), where L is the total length of all words, as each character is processed once.
Space Complexity: O(L), for storing the words.
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    if (s.length() > 10) {
      s = s[0] + to_string(s.length() - 2) + s[s.length() - 1];
    }
    cout << s << "\n";
  }
}