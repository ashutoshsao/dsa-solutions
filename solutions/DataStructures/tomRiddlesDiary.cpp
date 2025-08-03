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
