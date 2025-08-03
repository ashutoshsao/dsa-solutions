#include <iostream>
#include <limits>

class Solution {
public:
  double myPow(double x, int n) {
    // Explicitly handle 0^0 — defined as 1.0 in most programming contexts
    if (x == 0.0 && n == 0)
      return 1.0;

    // Handle 0 raised to a negative power — undefined
    if (x == 0.0 && n < 0)
      return std::numeric_limits<double>::infinity();

    // Convert to long long to safely handle n == INT_MIN
    long long N = n;
    if (N < 0) {
      x = 1.0 / x;
      N = -N;
    }

    return power(x, N);
  }

private:
  double power(double x, long long n) {
    if (n == 0)
      return 1.0;

    double half = power(x, n / 2);

    return (n % 2 == 0) ? half * half : half * half * x;
  }
};

int main() {
  Solution sol;

  // Test cases
  std::cout << "myPow(2.0, 10) = " << sol.myPow(2.0, 10) << std::endl;
  std::cout << "myPow(2.0, -2) = " << sol.myPow(2.0, -2) << std::endl;
  std::cout << "myPow(0.0, 5) = " << sol.myPow(0.0, 5) << std::endl;
  std::cout << "myPow(0.0, -3) = " << sol.myPow(0.0, -3) << std::endl;
  std::cout << "myPow(0.0, 0) = " << sol.myPow(0.0, 0) << std::endl;
  std::cout << "myPow(1.0, 12345) = " << sol.myPow(1.0, 12345) << std::endl;
  std::cout << "myPow(-1.0, 3) = " << sol.myPow(-1.0, 3) << std::endl;
  std::cout << "myPow(-1.0, 4) = " << sol.myPow(-1.0, 4) << std::endl;
  std::cout << "myPow(5.0, 0) = " << sol.myPow(5.0, 0) << std::endl;
  std::cout << "myPow(2.0, -2147483648) = " << sol.myPow(2.0, -2147483648)
            << std::endl;

  return 0;
}
