#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  unordered_map<string, string> mp;
  string name, ip;
  for (int i = 0; i < n; i++) {
    cin >> name >> ip;
    ip += ';';
    mp[ip] = name;
  }
  vector<string> v;
  string cmd;
  for (int j = 0; j < m; j++) {
    cin >> cmd >> ip;
    v.push_back(cmd + " " + ip + " # " + mp[ip]);
  }
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << "\n";
  }
}
