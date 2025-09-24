/*
Problem: Union of 2 Sorted Arrays
Link: https://www.geeksforgeeks.org/union-of-two-sorted-arrays/
Problem Statement: Given two sorted arrays, find their union (common and distinct elements).
Approach: The solution uses a two-pointer approach. It iterates through both arrays simultaneously, adding the smaller element to the result and advancing the corresponding pointer. If the elements are equal, it adds one of them and advances both pointers. It handles duplicates by only adding an element if it's different from the last one added to the result.
Time Complexity: O(N + M), where N and M are the sizes of the two arrays.
Space Complexity: O(N + M) in the worst case for the result vector.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> arr1(n), arr2(m), result;

  for (int i = 0; i < n; i++)
    cin >> arr1[i];
  for (int i = 0; i < m; i++)
    cin >> arr2[i];

  int p1 = 0, p2 = 0;
  while (p1 < n && p2 < m) {
    if (arr1[p1] < arr2[p2]) {
      if (result.empty() || result.back() != arr1[p1])
        result.push_back(arr1[p1]);
      p1++;
    } else if (arr1[p1] > arr2[p2]) {
      if (result.empty() || result.back() != arr2[p2])
        result.push_back(arr2[p2]);
      p2++;
    } else { // equal
      if (result.empty() || result.back() != arr1[p1])
        result.push_back(arr1[p1]);
      p1++;
      p2++;
    }
  }

  while (p1 < n) {
    if (result.empty() || result.back() != arr1[p1])
      result.push_back(arr1[p1]);
    p1++;
  }
  while (p2 < m) {
    if (result.empty() || result.back() != arr2[p2])
      result.push_back(arr2[p2]);
    p2++;
  }

  for (int x : result)
    cout << x << " ";
  cout << "\n";
  return 0;
}
