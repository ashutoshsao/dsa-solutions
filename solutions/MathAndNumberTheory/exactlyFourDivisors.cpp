// program to computer sum of divisors of  n numbers with eactly 4 divisors
#include <bits/stdc++.h>
using namespace std;

int countAndSumDivisors(int n) {
  int count = 0, sum = 0;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      int d1 = i;
      int d2 = n / i;

      if (d1 == d2) {
        count++;
        sum += d1;
      } else {
        count += 2;
        sum += d1 + d2;
      }
    }
  }

  return (count == 4) ? sum : 0;
}

int main() {
  int N;
  cin >> N;
  vector<int> nums(N);
  for (int i = 0; i < N; ++i)
    cin >> nums[i];

  int total = 0;
  for (int num : nums) {
    total += countAndSumDivisors(num);
  }

  cout << total << endl;
  return 0;
}
