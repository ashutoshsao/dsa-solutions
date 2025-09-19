/*
Problem: Queue at the School
Link: https://codeforces.com/problemset/problem/266/B
Problem Statement: During the break, the students in the queue in the canteen were bored. So they started to play a game. The queue is represented by a string of characters 'B' (boy) and 'G' (girl). In one second, if a boy is standing in front of a girl, they can swap their positions. Given the initial arrangement of the queue and the time `t`, find the arrangement of the queue after `t` seconds.
Approach: The solution simulates the process for `t` seconds. In each second, it iterates through the queue and swaps any adjacent pair of a boy followed by a girl ('BG'). This process is repeated `t` times to get the final arrangement.
Time Complexity: O(n*t), where n is the length of the queue and t is the given time.
Space Complexity: O(1), as the string is modified in-place.
*/
#include <bits/stdc++.h>
using namespace std;
void swap(string &s, int i, int j) {
  char temp = s[j];
  s[j] = s[i];
  s[i] = temp;
  return;
}
int main() {
  int n, t;
  cin >> n >> t;
  string s;
  cin >> s;
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (s[j] == 'B' && s[j + 1] == 'G') {
        swap(s, j, j + 1);
        j++;
      }
    }
  }
  cout << s << "\n";
}