// program for unordered_map anf its functions
#include <bits/stdc++.h>
using namespace std;

int main() {
  unordered_map<int, string> mp;
  mp[1] = "abc";
  mp[2] = "def";
  mp.insert({3, "ghi"});

  for (auto it = mp.begin(); it != mp.end(); it++) {
    cout << it->first << ": " << it->second << "\n";
  }

  auto p = mp.find(3); // Correct type: iterator
  if (p != mp.end()) {
    cout << "Found key 3: " << p->second << "\n";
  }
}
