#include <bits/stdc++.h>
using namespace std;
int main() {
  set<int> st = {2, 4, 6};
  for (auto it = st.begin(); it != st.end(); it++) {
    cout << *it << "\n";
  }
  cout << *(lower_bound(st.begin(), st.end(), 1)) << "\n";
  cout << *(upper_bound(st.begin(), st.end(), 1)) << "\n";
  cout << *(lower_bound(st.begin(), st.end(), 2)) << "\n";
  cout << *(upper_bound(st.begin(), st.end(), 2)) << "\n";
  cout << *(lower_bound(st.begin(), st.end(), 3)) << "\n";
  cout << *(upper_bound(st.begin(), st.end(), 3)) << "\n";
  cout << *(lower_bound(st.begin(), st.end(), 7)) << "\n";
  cout << *(upper_bound(st.begin(), st.end(), 7)) << "\n";
}
