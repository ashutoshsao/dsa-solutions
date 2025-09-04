/*
Problem: Largest Number
Link: https://leetcode.com/problems/largest-number/
Problem Statement: Given a list of non-negative integers nums, arrange them such that they form the largest number and return it. Since the result may be very large, you need to return a string instead of an integer.
Approach: The solution sorts the numbers (converted to strings) using a custom comparison function. The comparison `a + b > b + a` ensures that for any two numbers `a` and `b`, `a` is placed before `b` if `ab` (concatenation) is greater than `ba`. This ordering guarantees that the final concatenated string will be the largest possible number.
Time Complexity: O(n log n)
Space Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b) { return a + b > b + a; }

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    sort(nums.begin(), nums.end(), cmp);

    if (nums[0] == "0") {
      cout << "0\n";
      continue;
    }

    string s = "";
    for (string x : nums) {
      s += x;
    }
    cout << s << "\n";
  }
}