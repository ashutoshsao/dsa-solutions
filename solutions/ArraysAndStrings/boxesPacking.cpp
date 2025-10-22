/*
Problem: Boxes Packing
Link: https://codeforces.com/problemset/problem/903/C
Problem Statement: Mishka has got n empty boxes. For every i(1 \u2264 i \u2264 n), i-th box is a cube with side length a_i. Mishka can put a box i into another box j if the following conditions are met: i-th box is not put into another box; j-th box doesn't contain any other boxes; box i is smaller than box j (a_i < a_j). Mishka can put boxes into each other an arbitrary number of times. He wants to minimize the number of visible boxes. A box is called visible iff it is not put into some another box. Help Mishka to determine the minimum possible number of visible boxes!
Approach: The problem asks to minimize the number of visible boxes. A box is visible if it's not put inside another box. We can put a smaller box inside a larger one. If we have multiple boxes of the same size, they cannot be nested within each other. To minimize visible boxes, we want to create as many "chains" of nested boxes as possible. The limiting factor for the number of such chains is the count of the most frequent box size. For example, if there are 3 boxes of size 5, we will need at least 3 visible boxes, because these three boxes cannot be nested into each other. We can always arrange other boxes to be nested within these or other larger boxes. Therefore, the minimum number of visible boxes is equal to the maximum frequency of any box size.
Time Complexity: O(N) - where N is the number of boxes. This is achieved by using a hash map to count the frequency of each box size and then finding the maximum frequency.
Space Complexity: O(D) - where D is the number of distinct box sizes. In the worst case, D can be equal to N.
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  unordered_map<long long, int> cnt;
  cnt.reserve(n);
  for (long long x : a) {
    cnt[x]++;
  }
  int maxCount = 0;
  for (auto &p : cnt) {
    maxCount = max(maxCount, p.second);
  }
  cout << maxCount << "\n";

  return 0;
}