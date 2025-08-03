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
          line[i - k] == 'o' || line[i] == 'u') {
        currentVowels--;
      }
      // Update maximum
      maxVowels = max(maxVowels, currentVowels);
    }

    cout << maxVowels << endl;
  }
  return 0;
}
