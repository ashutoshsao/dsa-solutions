/*
Problem: C. Average Score
Link: https://codeforces.com/contest/81/problem/C
Problem Statement: Given n marks, assign 'a' of them to Safety Studies and 'b' to PE (a + b = n) to maximize the sum of the average scores of the two subjects.
Approach: To maximize the sum of averages, we should assign the highest marks to the subject with fewer marks. The solution reads n scores and stores them with their original indices. If a < b, it sorts the scores in descending order and assigns the top 'a' marks to Safety Studies. If a > b, it sorts in ascending order and assigns the 'a' smallest marks to Safety-Studies, effectively giving the 'b' largest marks to PE. If a == b, any distribution is optimal, so no sorting is done.
Time Complexity: O(N log N)
Space Complexity: O(N)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

  int t;
  cin >> t;
  int a, b;
  cin >> a >> b;

  vector<pair<int, int>> nums;
  nums.reserve(t);
  for (int i = 0; i < t; i++) {
    int x;
    cin >> x;
    nums.push_back({x, i});
  }

  if (a < b) {
    sort(nums.begin(), nums.end(), [](auto &p1, auto &p2) {
      if (p1.first != p2.first)
        return p1.first > p2.first;
      return p1.second < p2.second;
    });
  } else if (a > b) {
    sort(nums.begin(), nums.end(), [](auto &p1, auto &p2) {
      if (p1.first != p2.first)
        return p1.first < p2.first;
      return p1.second < p2.second;
    });
  } else {
    // No sorting required
  }

  vector<int> res(t, 2);
  for (int i = 0; i < a; i++) {
    res[nums[i].second] = 1;
  }

  for (int i = 0; i < t; i++) {
    cout << res[i] << " ";
  }
  cout << "\n";

  return 0;
}
