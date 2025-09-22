#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, int> mp;
  mp[1] = 2;
  mp[5];
  mp.at(5) = 6;
  mp.insert({3, 4});
  for (auto it = mp.begin(); it != mp.end(); it++) {
    cout << it->first << it->second << "\n";
  }
}
