/*
* Problem: Games
* Link: https://codeforces.com/problemset/problem/268/A
* Problem Statement: There are n football teams. For each team, you are given its home and away uniform colors. When a team plays at home, it wears its home uniform. When it plays away, it wears its away uniform. The only exception is when the host team's home uniform color is the same as the guest team's away uniform color. In this case, the guest team wears its home uniform. For each team, you need to find out how many times it will have to play in its home uniform and how many times in its away uniform.
* Approach: The problem asks us to count the total number of games where the guest team has to wear its home uniform. This happens when the host team's home uniform color is the same as the guest team's away uniform color. We can solve this by iterating through all possible pairs of teams (i, j) where i is the host and j is the guest. For each pair, we check if the home uniform color of team i is equal to the away uniform color of team j. If they are equal, we increment a counter. The final value of the counter is the answer.
* Time Complexity: O(n^2)
* Space Complexity: O(n) for storing the uniform colors
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt = 0;
  cin >> n;

  vector<pair<int, int>> arr(n);

  for (int i = 0; i <= n - 1; i++) {
    cin >> arr[i].first >> arr[i].second;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;
      if (arr[i].first == arr[j].second) {
        cnt++;
      }
    }
  }
  cout << cnt << "\n";
}
