/*
 * Problem: Minions and Voting
 * Link: https://www.codechef.com/MARCH18B/problems/MINVOTE
 * Problem Statement: There are N minions in a line, each with an influence level S_i. A minion j votes for minion i if S_j is greater than or equal to the sum of influence levels of all minions strictly between them. For each minion, calculate the total number of votes it receives.
 * Approach: The solution uses a clever approach with prefix sums and difference arrays. First, it calculates the prefix sum of the influence levels to quickly find the sum of any subarray. Then, for each minion j, it performs two binary searches: one to the left and one to the right. These searches find the range of minions that will vote for j. Instead of incrementing the vote count for each minion in the found range (which would be inefficient), it uses a difference array (named `votes`). It increments the start of the range and decrements the end of the range. Finally, a single pass over the difference array computes the final vote counts for each minion.
 * Time Complexity: O(N log N) due to the binary searches for each minion.
 * Space Complexity: O(N) for storing the prefix sums and the difference array for votes.
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> s(n + 1), prefix(n + 1), votes(n + 2, 0);

    for (int i = 1; i <= n; i++) {
      cin >> s[i];
      prefix[i] = prefix[i - 1] + s[i];
    }

    // For each minion j
    for (int j = 1; j <= n; j++) {
      // -------- Left side search --------
      int l = 1, r = j - 1, pos = j;
      while (l <= r) {
        int mid = (l + r) / 2;
        ll segSum = prefix[j - 1] - prefix[mid];
        if (s[j] >= segSum) {
          pos = mid;
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      if (pos < j) {
        votes[pos]++; // start adding votes
        votes[j]--;   // stop before j
      }

      // -------- Right side search --------
      l = j + 1, r = n, pos = j;
      while (l <= r) {
        int mid = (l + r) / 2;
        ll segSum = prefix[mid - 1] - prefix[j];
        if (s[j] >= segSum) {
          pos = mid;
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      if (pos > j) {
        votes[j + 1]++;
        votes[pos + 1]--;
      }
    }

    // Build final votes array
    for (int i = 1; i <= n; i++) {
      votes[i] += votes[i - 1];
      cout << votes[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
