class Solution {
public:
  long long combination(int a, int b) {
    long long res = 1;
    for (int i = 1; i <= b; ++i) {
      res = res * (a - b + i) / i;
    }
    return res;
  }

  int numberOfPaths(int m, int n) { return combination(m + n - 2, m - 1); }
};
