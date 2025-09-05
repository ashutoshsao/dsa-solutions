/*
 * Problem: B. Qualifying Contest
 * Link: https://codeforces.com/contest/659/problem/B
 * Problem Statement: From a list of participants, each with a name, region, and score, form a two-person team for each region. The team should consist of the two participants with the highest scores from that region. If there is a tie for the second-highest score (i.e., the second and third participants have the same score), the team is ambiguous.
 * Approach: The solution groups participants by their region. For each region, it sorts the participants in descending order of their scores. If two participants have the same score, the one who appeared earlier in the input is placed first. Then, it checks if a team can be formed. If there are fewer than two participants, a team cannot be formed. If there are more than two participants and the scores of the second and third participants are equal, the team is ambiguous, and the output is "?". Otherwise, the names of the top two participants are printed.
 * Time Complexity: O(N log N)
 * Space Complexity: O(N)
 */
#include <bits/stdc++.h>
using namespace std;

struct Triplet {
  string name;
  int team;
  int score;
  int idx;
};

bool cmp(const Triplet &a, const Triplet &b) {
  if (a.score != b.score)
    return a.score > b.score; // higher score first
  return a.idx < b.idx;       // earlier input first
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<Triplet>> participants(m + 1); // 1-indexed regions
  for (int i = 0; i < n; i++) {
    Triplet t;
    cin >> t.name >> t.team >> t.score;
    t.idx = i;
    participants[t.team].push_back(t);
  }

  for (int i = 1; i <= m; i++) {
    sort(participants[i].begin(), participants[i].end(), cmp);

    // check ambiguity
    if (participants[i].size() >= 3 &&
        participants[i][1].score == participants[i][2].score) {
      cout << "?\n";
    } else {
      cout << participants[i][0].name << " " << participants[i][1].name << "\n";
    }
  }

  return 0;
}
