/*
Algorithm: Counting Sort
Approach: A non-comparison sorting algorithm that works by counting the number of objects having distinct key values. It is only efficient when the range of potential items in the input is not much larger than the number of items. The implementation handles a range of numbers by finding the min and max elements.
Time Complexity: O(n + k) where n is the number of elements and k is the range of the input (max - min + 1).
Space Complexity: O(k) to store the frequency array.
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> input(n);
  for (int i = 0; i < n; i++) {
    cin >> input[i];
  }

  int maxn = INT_MIN, minn = INT_MAX;
  for (int i = 0; i < n; i++) {
    maxn = max(input[i], maxn);
    minn = min(input[i], minn);
  }
  vector<int> freq(maxn - minn + 1, 0);
  for (int i = 0; i < n; i++) {
    freq[input[i] - minn]++;
  }
  for (int i = 1; i <= maxn - minn; i++) {
    freq[i] += freq[i - 1];
  }
  vector<int> result(n);
  for (int i = n - 1; i >= 0; i--) {
    result[freq[input[i] - minn] - 1] = input[i];
    freq[input[i] - minn]--;
  }
  for (int i = 0; i < n; i++) {
    cout << result[i] << " ";
  }
  cout << "
";
}
