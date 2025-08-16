/*
 Problem: Number of Occurrences
 Link: https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
 Problem Statement: Given a sorted array and a target number, the task is to find the number of times the target appears in the array. The function should return the count of occurrences of the target value. If the target is not present in the array, the expected output is 0.
 Approach: The solution uses binary search to find the first and last occurrences of the target element in the sorted array. It has two helper functions, `firstOccurrence` and `lastOccurrence`, both of which use binary search to find the respective indices. The `countFreq` function then calculates the total number of occurrences by subtracting the first index from the last and adding 1. If the first occurrence is not found, it means the element is not in the array, and it returns 0.
 Time Complexity: O(log n)
 Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int firstOccurrence(vector<int> &arr, int k) {
    int low = 0, high = arr.size() - 1, ans = -1;
    while (low <= high) {
      int m = (low + high) / 2;
      if (arr[m] < k) {
        low = m + 1;
      } else if (arr[m] > k) {
        high = m - 1;
      } else {
        ans = m;
        high = m - 1; // search left side
      }
    }
    return ans;
  }

  int lastOccurrence(vector<int> &arr, int k) {
    int low = 0, high = arr.size() - 1, ans = -1;
    while (low <= high) {
      int m = (low + high) / 2;
      if (arr[m] < k) {
        low = m + 1;
      } else if (arr[m] > k) {
        high = m - 1;
      } else {
        ans = m;
        low = m + 1; // search right side
      }
    }
    return ans;
  }

  int countFreq(vector<int> &arr, int target) {
    int first = firstOccurrence(arr, target);
    if (first == -1)
      return 0;
    int last = lastOccurrence(arr, target);
    return (last - first) + 1;
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int k;
  cin >> k;

  Solution sol;
  cout << sol.countFreq(arr, k) << endl;
  return 0;
}
