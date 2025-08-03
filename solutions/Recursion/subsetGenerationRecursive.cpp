#include <iostream>
#include <vector>
using namespace std;

void printAllSubsets(vector<int> &arr, int n, int i, vector<int> &tmp, int s) {
  // Base case: if we've processed all elements
  if (i == n) {
    // Print the current subset
    cout << "{ ";
    for (int j = 0; j < s; j++) {
      cout << tmp[j] << " ";
    }
    cout << "}" << endl;
    return;
  }

  // Recursive case 1: Include current element
  tmp[s] = arr[i];
  printAllSubsets(arr, n, i + 1, tmp, s + 1);

  // Recursive case 2: Exclude current element
  printAllSubsets(arr, n, i + 1, tmp, s);
}

void generateSubsets(vector<int> &arr) {
  int n = arr.size(); // Using .size() method
  vector<int> tmp(n); // Create auxiliary vector with size n
  cout << "All subsets of the array:" << endl;
  printAllSubsets(arr, n, 0, tmp, 0);
}

int main() {
  vector<int> arr = {1, 2, 3};

  cout << "Original array: ";
  for (int x : arr) {
    cout << x << " ";
  }
  cout << endl << endl;

  generateSubsets(arr);

  return 0;
}
