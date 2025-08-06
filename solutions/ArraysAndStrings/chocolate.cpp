/*
 * Problem: 617B - Chocolate
 * Link: https://codeforces.com/problemset/problem/617/B
 * Problem Statement: You are given a chocolate bar represented by an array of 0s and 1s, where 1s are nuts. You want to cut the bar into several pieces, such that each piece has exactly one nut. You can only cut between adjacent segments. Find the number of ways to cut the chocolate bar.
 * Approach: The key idea is that cuts can only be made in the segments of zeros that are between two nuts. If there are no nuts, there are 0 ways. If there is one nut, there is 1 way. If there are multiple nuts, the number of ways is the product of (number of zeros between consecutive nuts + 1) for all pairs of consecutive nuts.
 * Time Complexity: O(n), where n is the number of segments in the chocolate bar.
 * Space Complexity: O(n) to store the array.
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> array(n);
  for (int i = 0; i < n; i++)
    cin >> array[i];

  int count = 0;
  long long result = 1; // use long long to avoid overflow
  int last = -1;

  for (int i = 0; i < n; i++) {
    if (array[i] == 1) {
      count++;
      if (last != -1) {
        int gap = i - last - 1;
        result *= (gap + 1);
      }
      last = i;
    }
  }

  if (count == 0)
    cout << 0 << endl;
  else
    cout << result << endl;

  return 0;
}
