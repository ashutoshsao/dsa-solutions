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
