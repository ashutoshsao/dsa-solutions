/*
 * Problem: Minimum length unsorted subarray, sorting which makes the complete array sorted
 * Link: https://www.geeksforgeeks.org/dsa/minimum-length-unsorted-subarray-sorting-which-makes-the-complete-array-sorted/
 * Problem Statement: Given an unsorted array arr[0..n-1] of size n, find the minimum length subarray arr[s..e] such that sorting this subarray makes the whole array sorted.
 * Approach: The provided C++ code implements a linear time (O(n)) and constant space (O(1)) algorithm.
 * 1. It first scans from the left to find the end of the sorted prefix (`s`).
 * 2. It then scans from the right to find the start of the sorted suffix (`e`).
 * 3. It finds the minimum and maximum elements within the initial `arr[s...e]` subarray.
 * 4. Finally, it expands the subarray boundaries by checking if any element in the left sorted part is greater than the subarray's minimum, or if any element in the right sorted part is smaller than the subarray's maximum.
 * Time Complexity: O(n), as the array is traversed a constant number of times.
 * Space Complexity: O(1), as it only uses a few variables to store indices and min/max values.
 */

#include <bits/stdc++.h>
using namespace std;

pair<int, int> findUnsortedSubarray(vector<int> &arr, int n) {
  int s = 0, e = n - 1;

  // Step 1: find initial left boundary
  while (s < n - 1 && arr[s] <= arr[s + 1])
    s++;
  if (s == n - 1)
    return {0, 0}; // already sorted

  // Step 2: find initial right boundary
  while (e > 0 && arr[e] >= arr[e - 1])
    e--;

  // Step 3: find min & max in arr[s..e]
  int sub_min = arr[s], sub_max = arr[s];
  for (int i = s; i <= e; i++) {
    sub_min = min(sub_min, arr[i]);
    sub_max = max(sub_max, arr[i]);
  }

  // Step 4: expand s leftward
  while (s > 0 && arr[s - 1] > sub_min)
    s--;

  // Step 5: expand e rightward
  while (e < n - 1 && arr[e + 1] < sub_max)
    e++;

  return {s, e};
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
      cin >> arr[i];

    auto ans = findUnsortedSubarray(arr, n);
    cout << ans.first << " " << ans.second << "\n";
  }
  return 0;
}
