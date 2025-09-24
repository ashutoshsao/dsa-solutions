/*
Problem: C++ STL Pair Demonstration
Link:
Problem Statement: This program demonstrates the usage of `std::pair` in C++, a container that stores two heterogeneous objects as a single unit.

Approach:
- A `std::pair` named `p1` is initialized with two integer values.
- The program then accesses and prints the `first` and `second` elements of the pair.

Time Complexity:
- Accessing elements (`.first`, `.second`) is a constant time operation, O(1).

Space Complexity: O(1) for the pair itself, though the size depends on the types of the elements it holds.
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  pair<int, int> p1 = {1, 2};
  cout << p1.first << "\t" << p1.second << "\n";
  return 0;
}
