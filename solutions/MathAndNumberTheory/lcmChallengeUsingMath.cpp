// program to compute largest lcm of a,b,c <=n 1<=n<=10^6
#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n == 1) { // Base case for n=1
    cout << 1 << "\n";
  } else if (n == 2) { // Base case for n=2
    cout << 2 << "\n";
  } else if (n == 3) { // Base case for n=3
    cout << 6 << "\n";
  } else {                            // General cases for n >= 4
    long long result;                 // Variable to store the maximum LCM
    if (n % 2 != 0) {                 // If n is odd
      result = n * (n - 1) * (n - 2); // LCM of n, n-1, n-2 (pairwise coprime)
    } else {                          // If n is even
      if (n % 3 == 0) { // If n is a multiple of 3 (so n is a multiple of 6)
        result = (n - 1) * (n - 2) * (n - 3); // LCM of n-1, n-2, n-3
      } else {                          // If n is even but not a multiple of 3
        result = n * (n - 1) * (n - 3); // LCM of n, n-1, n-3
      }
    }
    cout << result << "\n"; // Output the maximum LCM
  }

  return 0; // Indicate successful execution
}
