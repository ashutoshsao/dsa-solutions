/*
Problem: Minimum Swaps to Bring Elements Less Than or Equal to K Together
Link: https://www.geeksforgeeks.org/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together/
Problem Statement: Given an array of n positive integers and a number k, find the minimum number of swaps required to bring all the numbers less than or equal to k together.
Approach: The solution uses a sliding window approach. First, it counts the total number of elements that are less than or equal to `k`. This count determines the size of the sliding window. It then slides a window of this size through the array, keeping track of the maximum number of "good" elements (elements <= k) found in any window. The minimum number of swaps required is the total count of "good" elements minus the maximum number of "good" elements found in any window.
Time Complexity: O(n), as it involves a single pass through the array to count good elements and another pass for the sliding window.
Space Complexity: O(1), as it uses only a few variables for counts.
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  int maxLegal = 0;
  for (int i = 0; i < n;
 i++) {
    cin >> arr[i];
    if (arr[i] <= k)
      maxLegal++;
  }
  int cnt = 0;
  for (int i = 0; i < maxLegal; i++) {
    if (arr[i] <= k)
      cnt++;
  }
  int maxCnt = cnt;
  for (int i = maxLegal; i < n; i++) {
    if (arr[i] <= k) {
      cnt++;
    }
    if (arr[i - maxLegal] <= k) {
      cnt--;
    }
    maxCnt = max(maxCnt, cnt);
  }
  cout << maxLegal - maxCnt << "\n";
}