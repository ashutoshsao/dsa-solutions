/*
Problem: Sort Elements by Frequency
Link: https://www.geeksforgeeks.org/sort-elements-by-frequency/
Problem Statement: Given an array of integers, sort the array according to the frequency of elements. Elements with higher frequency should come first. If two elements have the same frequency, the smaller element should come first.
Approach: The solution uses a hash map to count the frequency of each element. Then, it stores pairs of (value, frequency) in a vector. Finally, it sorts this vector using a custom comparator. The comparator sorts by frequency in descending order. If frequencies are equal, it sorts by value in ascending order.
Time Complexity: O(n log n)
Space Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;

struct Dual {
  int val;
  int freq;
};

bool cmp(Dual x, Dual y) {
  if (x.freq != y.freq)
    return x.freq > y.freq;
  return x.val < y.val;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    unordered_map<int, int> freq;
    for (int x : nums) {
      freq[x]++;
    }
    vector<Dual> numsFreq;
    for (auto &p : nums) {
      numsFreq.push_back({p, freq[p]});
    }
    sort(numsFreq.begin(), numsFreq.end(), cmp);

    for (auto &p : numsFreq) {
      cout << p.val << " ";
    }
    cout << "\n";
  }
  return 0;
}