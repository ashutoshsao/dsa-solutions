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
