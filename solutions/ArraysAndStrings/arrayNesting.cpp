/*
 * Problem: 565. Array Nesting
 * Link: https://leetcode.com/problems/array-nesting/
 * Problem Statement: You are given an integer array nums of length n where nums is a permutation of the numbers in the range [0, n - 1]. You should build a set s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ...} subjected to the following rule: The first element in s[k] starts with the selection of the element nums[k] of index = k. The next element in s[k] should be nums[nums[k]], and so on. We stop adding right before a duplicate element occurs in s[k]. Return the longest length of a set s[k].
 * Approach: The problem can be modeled as finding the longest cycle in a directed graph where each index i has an edge to nums[i]. We can iterate through each element, and if it hasn't been visited yet, we traverse its cycle, counting the length and marking elements as visited. The maximum length found is the answer.
 * Time Complexity: O(n), as each element is visited exactly once.
 * Space Complexity: O(n) for the visited array. An O(1) space solution is possible by modifying the input array to mark visited elements.
 */
// in this progrma we are checking for max length of a set in form
// {arr[i],arr[arr[i]],arr[arr[arr[i]]],,}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vector<bool> visited(n, false);
  int maxCnt = 0;

  for (int i = 0; i < n; i++) {
    if (visited[i])
      continue;

    int cnt = 0;
    int idx = i;

    while (!visited[idx]) {
      visited[idx] = true;
      idx = nums[idx];
      cnt++;
    }

    maxCnt = max(maxCnt, cnt);
  }

  cout << maxCnt << endl;
  return 0;
}
