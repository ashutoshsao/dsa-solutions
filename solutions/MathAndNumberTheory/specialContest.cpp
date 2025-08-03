#include <bits/stdc++.h>
using namespace std;
long long gcdAB(long long A, long long B) {
  long long minm = min(A, B);
  long long maxm = max(A, B);
  while (minm != 0) {
    long long temp = maxm;
    maxm = minm;
    minm = temp % minm;
  }
  return maxm;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long N, A, B, K;
    cin >> N >> A >> B >> K;
    if (N < K) {
      cout << "Lose" << "\n";
      continue;
    }
    long long divByA = N / A;
    long long divByB = N / B;
    long long lcmAB = (A / gcdAB(A, B)) * B;
    long long ans = divByA + divByB - (2 * (N / lcmAB));
    if (ans >= K)
      cout << "Win" << "\n";
    else
      cout << "Lose" << "\n";
  }
}
