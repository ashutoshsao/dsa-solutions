/*
Problem: Letter Tile Possibilities
Link: https://leetcode.com/problems/letter-tile-possibilities/description/
Problem Statement: The problem asks you to find the number of possible non-empty sequences that can be formed using a given set of letter tiles. Each tile has a single letter printed on it. You need to count all unique sequences that can be created by arranging these letters.
Approach: The solution uses a recursive backtracking approach. The `numTilePossibilities` function first counts the frequency of each character in the input `tiles` string and stores it in an `unordered_map`. The core logic is in the `getCntOfTiles` helper function, which takes the frequency map as input. This function iterates through each character in the frequency map. If a character's count is greater than 0, it means we can use this tile. We decrement its count, increment the `total` count (as we've formed a new sequence of length 1), and then recursively call `getCntOfTiles` with the updated frequency map to explore possibilities with the remaining tiles. After the recursive call returns, we increment the character's count back to backtrack and explore other possibilities. This ensures that all unique sequences are counted.
Time Complexity: O(N * 2^N) where N is the number of unique characters in the input string. In the worst case, if all characters are unique, it's roughly O(N!).
Space Complexity: O(N) for the frequency map and recursion stack.
*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int getCntOfTiles(unordered_map<char, int> &freq) {
    int total = 0;
    for (auto &[ch, count] : freq) {
      if (count == 0)
        continue;
      freq[ch]--;
      total += 1;
      total += getCntOfTiles(freq);
      freq[ch]++;
    }
    return total;
  }

  int numTilePossibilities(string tiles) {
    unordered_map<char, int> freq;
    for (char c : tiles) {
      freq[c]++;
    }
    return getCntOfTiles(freq);
  }
};

int main() {
  string tiles = "AAB";

  Solution sol;
  int result = sol.numTilePossibilities(tiles);

  cout << result << endl;

  return 0;
}
