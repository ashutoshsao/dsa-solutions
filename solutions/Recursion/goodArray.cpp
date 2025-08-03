// Bézout's Identity:
// For any two non-zero integers 'a' and 'b', there exist integers 'x' and 'y'
// (called Bézout coefficients) such that:

// ax+by=gcd(a,b)

// Furthermore, the greatest common divisor, gcd(a,b), is the smallest positive
// integer that can be expressed as a linear combination of 'a' and 'b'.
#include <algorithm> // for swap
#include <iostream>  // for cin, cout
#include <vector>    // for vector

using namespace std;

int gcd(int a, int b) {
  while (b != 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    int currentGCD = nums[0];
    for (int i = 1; i < n; i++) {
      if (currentGCD == 1)
        break;
      currentGCD = gcd(currentGCD, nums[i]);
    }

    if (currentGCD == 1)
      cout << "true\n";
    else
      cout << "false\n";
  }

  return 0;
}
