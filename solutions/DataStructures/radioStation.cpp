/*
Problem: Radio Station
Link: https://codeforces.com/problemset/problem/918/B
Problem Statement: You are given N server names and their corresponding IP addresses. Then, you are given M queries. Each query consists of a command and an IP address followed by a semicolon. For each query, you need to output the command, the original IP address with the semicolon, and the server name corresponding to that IP address.

Approach:
The problem can be efficiently solved using a hash map (`std::unordered_map` in C++) to store the mapping from IP addresses to server names.
First, read N and M.
Then, in a loop N times, read the server name and IP address. The problem statement mentions the IP address in the queries has a semicolon at the end, so we add it to the IP before storing it in the map. The IP address becomes the key and the server name is the value.
After populating the map, loop M times for the queries. In each iteration, read the command and the IP address string.
Once the server name is retrieved from the map using the IP address, print the command, the original IP address string, and the found server name.

Time Complexity:
O(N + M), where N is the number of server-IP pairs and M is the number of queries.
Populating the hash map takes O(N) time on average.
Each lookup in the hash map takes O(1) time on average. Since there are M queries, processing queries takes O(M) time on average.
Therefore, the total time complexity is O(N + M).

Space Complexity:
O(N), where N is the number of server-IP pairs.
The hash map stores N entries, each containing an IP address and a server name.
*/
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
