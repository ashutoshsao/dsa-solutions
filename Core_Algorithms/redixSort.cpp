/*
Algorithm: Radix Sort
Approach: This implementation of Radix Sort is tailored for a specific scenario where the maximum element in the array is less than n^2, 'n' being the number of elements. It works by treating the numbers as if they are in base-n. The sorting process involves two main passes of a stable sorting algorithm, Counting Sort.
1.  **First Pass (LSD):** The array is sorted based on the least significant digit (LSD) of each number in base-n. This is calculated as `element % n`.
2.  **Second Pass (MSD):** The array is then sorted based on the most significant digit (MSD) in base-n. This is calculated as `(element / n) % n`.
Because Counting Sort is a stable algorithm, the relative order of elements with the same MSD is preserved from the first pass, which ultimately leaves the entire array sorted.
Time Complexity:
  - O(n + k), where 'k' is the base of the numbers. In this specific implementation, k = n, so the complexity for one pass is O(n).
  - Since there are two passes, the total time complexity is O(2n), which simplifies to O(n).
Space Complexity: O(n + k) for the auxiliary 'count' and 'aux' arrays. Since k = n, the space complexity is O(n).
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  void sort(int arr[], int n) {
    if (n <= 1) return;
    vector<int> count(n, 0), aux(n);
    // once place
    for (int i = 0; i < n; i++) {
      count[arr[i] % n]++;
    }
    for (int i = 1; i < n; i++) {
      count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
      aux[count[arr[i] % n] - 1] = arr[i];
      count[arr[i] % n]--;
    }
    for (int i = 0; i < n; i++) {
      arr[i] = aux[i];
      count[i] = 0;
    }
    // for tens place
    for (int i = 0; i < n; i++) {
      count[(arr[i] / n) % n]++;
    }
    for (int i = 1; i < n; i++) {
      count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
      aux[count[(arr[i] / n) % n] - 1] = arr[i];
      count[(arr[i] / n) % n]--;
    }
    for (int i = 0; i < n; i++) {
      arr[i] = aux[i];
      count[i] = 0;
    }
  }
};

int main() {
  int n;
  cin >> n; // Read size of array

  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i]; // Read array elements
  }

  Solution obj;
  obj.sort(arr, n); // Call radix sort on entire array

  for (int i = 0; i < n; i++) { // Print sorted array
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}