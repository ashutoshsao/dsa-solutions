/*
Problem: Make Them Odd
Link: https://codeforces.com/problemset/problem/1277/B
Problem Statement: You are given a set of n distinct positive integers. In one operation, you can choose any even integer x from the set and replace it with x/2. You need to find the minimum number of operations to make all integers in the set odd.
Approach: The solution uses a set to store the initial numbers, which automatically handles duplicates and keeps them sorted. It then iterates through the set. For each even number, it divides it by 2 and inserts the result back into the set. This process is repeated until all numbers in the set are odd. A counter is used to keep track of the number of operations. The use of a set is important because if we encounter a number that has already been processed (i.e., an even number whose half is already in the set), we don't need to process it again.
Time Complexity: The time complexity is not straightforward to analyze. In the worst case, a number can be of the order of 10^9, which is less than 2^30. So, a number can be divided by 2 at most 30 times. With n numbers, the total number of operations would be at most 30*n. Each operation on the set (insertion, deletion) takes O(log S) time, where S is the size of the set.
Space Complexity: O(n) to store the numbers in the set.
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int val;
    set<int> st;
    for (int i = 0; i < n; i++) {
      cin >> val;
      st.insert(val);
    }
    int cnt = 0;
    while (!st.empty()) {
      val = *st.rbegin();
      st.erase(val);
      if (val % 2 == 0) {
        st.insert(val / 2);
        cnt++;
      }
    }
    cout << cnt << "\n";
  }
}
