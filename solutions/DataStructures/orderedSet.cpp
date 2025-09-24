/*
Problem: C++ STL Set Demonstration
Link:
Problem Statement: This program demonstrates the usage of `std::set` in C++, a container that stores unique elements in a sorted order. It showcases iteration, and the use of `lower_bound` and `upper_bound` functions.

Approach:
- A `std::set` named `st` is initialized with integer values.
- The program iterates through the set and prints its elements, demonstrating the sorted nature of the set.
- `lower_bound(value)`: Returns an iterator to the first element that is not less than the given value.
- `upper_bound(value)`: Returns an iterator to the first element that is greater than the given value.
- The program then demonstrates the usage of `lower_bound` and `upper_bound` with different values to find elements within the set.

Time Complexity:
- Insertion, deletion, and search operations in `std::set` have a time complexity of O(log n), where n is the number of elements in the set.
- `lower_bound` and `upper_bound` also have a time complexity of O(log n).

Space Complexity: O(n) to store the elements in the set.
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  set<int> st = {2, 4, 6};
  for (auto it = st.begin(); it != st.end(); it++) {
    cout << *it << "\n";
  }
  cout << *(lower_bound(st.begin(), st.end(), 1)) << "\n";
  cout << *(upper_bound(st.begin(), st.end(), 1)) << "\n";
  cout << *(lower_bound(st.begin(), st.end(), 2)) << "\n";
  cout << *(upper_bound(st.begin(), st.end(), 2)) << "\n";
  cout << *(lower_bound(st.begin(), st.end(), 3)) << "\n";
  cout << *(upper_bound(st.begin(), st.end(), 3)) << "\n";
  cout << *(lower_bound(st.begin(), st.end(), 7)) << "\n";
  cout << *(upper_bound(st.begin(), st.end(), 7)) << "\n";
}
