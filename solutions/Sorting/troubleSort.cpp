/*
* Problem: Trouble Sort
* Link: https://dmoj.ca/problem/gcj18qrb
* Problem Statement: A new sorting algorithm, "Trouble Sort", examines triplets of adjacent numbers and reverses the triplet if the first number is larger than the third. The task is to determine if Trouble Sort will correctly sort a given list of integers into non-decreasing order. If not, find the index of the first element that is larger than the one immediately following it after the algorithm finishes.
* Approach: The solution separates the list into two sub-lists: one containing elements at even indices and the other containing elements at odd indices. It sorts these two sub-lists independently and then merges them back. Finally, it iterates through the merged list to find the first index where the non-decreasing order is violated.
* Time Complexity: O(N log N)
* Space Complexity: O(N)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  int Case = 1;
  while (t--) {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    vector<int> tmp1, tmp2;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0)
        tmp1.push_back(nums[i]);
      else
        tmp2.push_back(nums[i]);
    }

    sort(tmp1.begin(), tmp1.end());
    sort(tmp2.begin(), tmp2.end());

    int x1 = 0, x2 = 0;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0)
        nums[i] = tmp1[x1++];
      else
        nums[i] = tmp2[x2++];
    }

    int badIndex = -1;
    for (int i = 0; i < n - 1; i++) {
      if (nums[i] > nums[i + 1]) {
        badIndex = i;
        break;
      }
    }

    if (badIndex == -1)
      cout << "Case #" << Case << ": OK\n";
    else
      cout << "Case #" << Case << ": " << badIndex << "\n";

    Case++;
  }
}
