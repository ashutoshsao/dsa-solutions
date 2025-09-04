/*
Problem: Relative Sort Array
Link: https://leetcode.com/problems/relative-sort-array/
Problem Statement: Given two arrays, arr1 and arr2, where the elements of arr2 are distinct and are all present in arr1, you need to sort arr1 such that the relative order of elements that also appear in arr2 is the same as in arr2. Elements from arr1 that are not in arr2 should be placed at the end of the sorted array in ascending order.
Approach: The solution uses a custom comparator with a hash map (unordered_map in C++) to store the ranks of elements in arr2. The comparator function then sorts arr1 based on these ranks. Elements not in arr2 are sorted based on their natural order.
Time Complexity: O(n log n)
Space Complexity: O(m)
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> rankMap;

// Comparator function
bool cmp(int a, int b) {
  bool inA = rankMap.find(a) != rankMap.end();
  bool inB = rankMap.find(b) != rankMap.end();

  if (inA && inB) {
    return rankMap[a] < rankMap[b]; // both in arr2 → order by rank
  } else if (inA) {
    return true; // a in arr2, b not → a first
  } else if (inB) {
    return false; // b in arr2, a not → b first
  } else {
    return a < b; // neither in arr2 → ascending
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> nums1(n);

  for (int i = 0; i < n; i++) {
    cin >> nums1[i];
  }

  vector<int> nums2(m);
  for (int i = 0; i < m; i++) {
    cin >> nums2[i];
  }

  for (int i = 0; i < m; i++) {
    rankMap[nums2[i]] = i;
  }

  sort(nums1.begin(), nums1.end(), cmp);

  // Print result
  for (int x : nums1)
    cout << x << " ";
  cout << "\n";

  return 0;
}