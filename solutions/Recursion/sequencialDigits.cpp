/*
Problem: Sequential Digits
Link: https://leetcode.com/problems/sequential-digits/description/
Problem Statement: An integer has sequential digits if and only if each digit in the number is one more than the previous digit. Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.
Approach: The solution uses a recursive approach. A helper function `buildSequential` is used to construct numbers with sequential digits. This function is initially called for each possible starting digit (1 through 9). The recursive function builds the number and if it falls within the given range [low, high], it's added to the result vector. The base cases for the recursion are when the current number exceeds `high` or the next digit to be appended is greater than 9. Finally, the result vector is sorted.
Time Complexity: The number of sequential numbers is small and constant. The generation of each number takes O(log k) where k is the number. The number of such numbers is small. Let's say it's N. Sorting these N numbers takes O(N log N).
Space Complexity: O(N) to store the sequential numbers in the result vector.
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class solution {
public:
  void buildSequential(int current, int nextDigit, int low, int high,
                       vector<int> &result) {
    if (current >= low && current <= high) {
      result.push_back(current);
    }
    if (current > high || nextDigit > 9) {
      return;
    }

    // Append next digit
    int next = current * 10 + nextDigit;
    buildSequential(next, nextDigit + 1, low, high, result);
  }

  vector<int> sequentialDigits(int low, int high) {
    vector<int> result;

    // Try starting with every digit from 1 to 9
    for (int i = 1; i <= 9; ++i) {
      buildSequential(0, i, low, high, result);
    }

    sort(result.begin(), result.end()); // optional, to ensure order
    return result;
  }
};
int main() {
  solution sol;
  int low = 1000, high = 13000;
  vector<int> res = sol.sequentialDigits(low, high);

  for (int num : res)
    cout << num << " ";
  cout << endl;

  return 0;
}
