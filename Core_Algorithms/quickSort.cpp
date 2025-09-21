/*
Algorithm: Quick Sort
Approach: A divide-and-conquer algorithm that works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively. This implementation uses the last element as the pivot.
Time Complexity:
  - Best Case: O(n log n)
  - Average Case: O(n log n)
  - Worst Case: O(n^2)
Space Complexity: O(log n) for the recursion stack.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  void quickSort(vector<int> &arr, int i, int j) {
    if (i < j) {
      int p = partition(arr, i, j);
      quickSort(arr, i, p - 1);
      quickSort(arr, p + 1, j);
    }
  }

public:
  int partition(vector<int> &arr, int i, int j) {
    int l = i, r = j - 1;
    while (l <= r) {
      while (l <= r && arr[l] <= arr[j])
        l++;
      while (l <= r && arr[r] > arr[j])
        r--;
      if (l < r)
        swap(arr[l], arr[r]);
    }
    swap(arr[j], arr[l]);
    return l;
  }
};

int main() {
  int n;
  cin >> n; // Read size of array

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i]; // Read array elements
  }

  Solution obj;
  obj.quickSort(arr, 0, n - 1); // Call quick sort on entire array

  for (int x : arr) { // Print sorted array
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
