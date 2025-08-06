/*
* Problem: Majority Element II
* Link: https://leetcode.com/problems/majority-element-ii/
* Problem Statement: Given an integer array of size n, find all elements that appear more than âŒŠ n/3 âŒ‹ times.
* Approach: The problem is solved using an extension of the Boyer-Moore Voting Algorithm. Since we are looking for elements that appear more than n/3 times, there can be at most two such elements. The algorithm works in two passes:
* 1. **Candidate Identification:**
*    - We maintain two candidates (candidate1, candidate2) and their counts (count1, count2).
*    - We iterate through the array. If the current element is one of the candidates, we increment its count. If a count is zero, we assign the current element to the corresponding candidate and set the count to 1. If the current element is not a candidate and both counts are non-zero, we decrement both counts.
* 2. **Candidate Verification:**
*    - After the first pass, we have two potential candidates.
*    - We iterate through the array again to count the actual occurrences of the two candidates.
*    - If a candidate's count is greater than n/3, it is added to the result.
* Time Complexity: O(n)
* Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
      cin >> nums[i];

    int candidate1 = 0, candidate2 = 0;
    int count1 = 0, count2 = 0;

    for (int i = 0; i < n; ++i) {
      int num = nums[i];
      if (count1 > 0 && num == candidate1) {
        count1++;
      } else if (count2 > 0 && num == candidate2) {
        count2++;
      } else if (count1 == 0) {
        candidate1 = num;
        count1 = 1;
      } else if (count2 == 0) {
        candidate2 = num;
        count2 = 1;
      } else {
        count1--;
        count2--;
      }
    }

    // Second pass to verify
    count1 = count2 = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == candidate1)
        count1++;
      else if (nums[i] == candidate2)
        count2++;
    }

    vector<int> result;
    if (count1 > n / 3)
      result.push_back(candidate1);
    if (count2 > n / 3 && candidate2 != candidate1)
      result.push_back(candidate2);

    if (result.empty()) {
      cout << -1;
    } else {
      sort(result.begin(), result.end()); // sort the result
      for (int num : result) {
        cout << num << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}
