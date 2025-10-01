/*
Problem: Minimize max(A[i], B[j], C[k]) - min(A[i], B[j], C[k])
Link: https://www.geeksforgeeks.org/dsa/minimize-maxai-bj-ck-minai-bj-ck-three-different-sorted-arrays/
Problem Statement: Given three sorted arrays A, B, and C, find the minimum absolute difference between the maximum and minimum of any triplet A[i], B[j], C[k].
Approach: The solution uses a three-pointer approach. Three pointers, one for each array, are initialized to the beginning. In each step, the current difference between the maximum and minimum of the three elements is calculated and the overall minimum difference is updated. To minimize the difference, the pointer corresponding to the minimum element among the three is incremented. This process continues until one of the pointers reaches the end of its array.
Time Complexity: O(n1 + n2 + n3), where n1, n2, and n3 are the sizes of the arrays.
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int findMinDiff(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
  int i = 0, j = 0, k = 0, ans = INT_MAX, n1 = arr1.size(), n2 = arr2.size(),
      n3 = arr3.size();
  while (i < n1 && j < n2 && k < n3) {
    int val = max(arr1[i], max(arr2[j], arr3[k])) -
              min(arr1[i], min(arr2[j], arr3[k]));
    ans = min(ans, val);

    int minM = min(arr1[i], min(arr2[j], arr3[k]));
    if (minM == arr1[i])
      i++;
    else if (minM == arr2[j])
      j++;
    else
      k++;
  }
  return ans;
}

int main() {
  vector<int> arr1 = {1, 4, 5, 8, 10};
  vector<int> arr2 = {6, 9, 15};
  vector<int> arr3 = {2, 3, 6, 6};
  int ans = findMinDiff(arr1, arr2, arr3);
  cout << ans << "\n";
}