// in this programm we are prinint prime factors and their exponenets
// num = 10
// output
// 2 1
// 5 1
#include <bits/stdc++.h>
using namespace std;
int main() {
  int maxN = 1000000;

  vector<bool> isPrime(maxN + 1, true);
  vector<int> spf(maxN + 1, -1);
  isPrime[0] = isPrime[1] = false;

  for (int i = 2; i * i <= maxN; i++) {
    if (isPrime[i]) {
      for (int j = i; i * j <= maxN; j++) {
        if (spf[i * j] == -1) {
          spf[i * j] = i;
        }
        isPrime[i * j] = false;
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int, int> count;
    int temp = n;
    while (temp > 1) {
      int prime = spf[temp];
      if (prime == -1) {
        count[temp]++;
        break;
      }
      count[prime]++;
      temp = temp / prime;
    }
    for (auto &p : count) {
      cout << p.first << " " << p.second << "\n";
    }
  }
  return 0;
}
