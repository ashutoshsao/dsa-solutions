#include <iostream>
#include <string>
using namespace std;

// Recursive function to calculate super digit
int getSuperDigit(long long num) {
  if (num < 10) {
    return static_cast<int>(
        num); // since c++ needs explicit typecasting for narrow typecasting
  }
  // Calculate sum of digits
  long long sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return getSuperDigit(sum);
}

int superDigit(string n, int k) {
  // Calculate sum of digits in the string
  long long digitSum = 0;
  for (char &c : n) {
    digitSum += (c - '0');
  }
  // Total sum after k repetitions
  long long totalSum = digitSum * k;
  return getSuperDigit(totalSum);
}

int main() {
  string n = "123";
  int k = 3;
  int result = superDigit(n, k);
  cout << result << endl;
  return 0;
}
