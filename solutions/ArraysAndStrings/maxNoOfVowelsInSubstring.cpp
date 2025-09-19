/*
Problem: Maximum Number of Vowels in a Substring of Given Length
Link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
Problem Statement: Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
Approach: The solution uses a sliding window approach. It first calculates the number of vowels in the first window of size `k`. Then, it slides the window one character at a time. In each step, it updates the vowel count by checking the character entering and leaving the window. The maximum vowel count seen during the process is the answer.
Time Complexity: O(n), where n is the length of the string, as it involves a single pass through the string.
Space Complexity: O(1), as it uses only a few variables to keep track of the vowel count.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string line;
    int k, maxVowels = 0, currentVowels = 0;
    cin >> line >> k;

    // Count vowels in first window
    for (int i = 0; i < k; i++) {
      if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' ||
          line[i] == 'o' || line[i] == 'u') {
        currentVowels++;
      }
    }
    maxVowels = currentVowels;

    // Sliding window approach
    for (int i = k; i < line.length(); i++) {
      // Add new character to window
      if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' ||
          line[i] == 'o' || line[i] == 'u') {
        currentVowels++;
      }
      // Remove character that's leaving the window
      if (line[i - k] == 'a' || line[i - k] == 'e' || line[i - k] == 'i' ||
          line[i - k] == 'o' || line[i - k] == 'u') {
        currentVowels--;
      }
      // Update maximum
      maxVowels = max(maxVowels, currentVowels);
    }

    cout << maxVowels << endl;
  }
  return 0;
}