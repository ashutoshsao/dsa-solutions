/*
Problem: Tom Riddle's Diary
Link: https://codeforces.com/problemset/problem/855/A
Problem Statement: You are given n names, one on each line. For each name, you need to check if you have seen this name before. If you have, print "YES", otherwise print "NO".

Approach:
The problem can be solved by using a hash set (`std::unordered_set` in C++) to keep track of the names encountered so far.
- Read the number of names, n.
- Loop n times:
  - Read the current name.
  - Check if the name exists in the hash set.
    - If it does, print "YES".
    - If it doesn't, print "NO" and insert the name into the hash set.

Time Complexity:
O(N * L), where N is the number of names and L is the average length of a name.
- The average time complexity of insertion and search in `std::unordered_set` is O(L) because of hashing the string.
- We perform these operations for each of the N names.

Space Complexity:
O(N * L), to store the N names in the hash set.
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  unordered_set<string> st;
  int n;
  cin >> n;
  string name;
  for (int i = 0; i < n; i++) {
    cin >> name;
    if (st.find(name) != st.end())
      cout << "YES";
    else {
      cout << "NO";
      st.insert(name);
    }
    cout << "\n";
  }
}
