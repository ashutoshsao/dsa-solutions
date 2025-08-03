// program to compute largest lcm of a,b,c <=n 1<=n<=10^6
#include <bits/stdc++.h>

using namespace std;

// Compute GCD (Euclidean Algorithm)
long long GCD(long long a, long long b) {
  while (b != 0) {
    a = a % b;
    swap(a, b);
  }
  return a;
}

// Compute LCM of two numbers
long long LCM(long long a, long long b) { return a / GCD(a, b) * b; }

// Compute LCM of three numbers
long long LCM3(long long a, long long b, long long c) {
  return LCM(LCM(a, b), c);
}

int main() {
  long long n;
  cin >> n;

  long long maxLCM = 0;

  // Full iteration for small n
  if (n <= 100) {
    for (long long a = n; a >= 1; --a)
      for (long long b = a; b >= 1; --b)
        for (long long c = b; c >= 1; --c)
          maxLCM = max(maxLCM, LCM3(a, b, c));
  } else {
    // Smart iteration for large (n to n-100) - only top values
    for (long long a = n; a >= n - 100; --a)
      for (long long b = a; b >= n - 100; --b)
        for (long long c = b; c >= n - 100; --c)
          maxLCM = max(maxLCM, LCM3(a, b, c));
  }

  cout << maxLCM << "\n";

  return 0;
}
