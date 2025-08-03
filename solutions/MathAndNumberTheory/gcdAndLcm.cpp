#include <bits/stdc++.h>
using namespace std;
long long gcdFunc(long long minm, long long maxm) {
  if (minm == 0)
    return maxm;
  while (maxm % minm != 0) {
    long long temp = maxm;
    maxm = minm;
    minm = temp % minm;
  }
  return minm;
}

long long lcmFunc(long long a, long long b, long long gcd) {
  long long lcm = (a / gcd) * b;
  return lcm;
}

int main() {
  long long a, b;
  cin >> a >> b;
  long long minm, maxm;
  minm = min(a, b);
  maxm = max(a, b);
  long long gcd = gcdFunc(minm, maxm);
  long long lcm = lcmFunc(a, b, gcd);
  cout << gcd << " " << lcm << endl;
}
