/*
* Problem: Count pairs in array whose sum is divisible by K
* Link: https://www.geeksforgeeks.org/count-pairs-in-array-whose-sum-is-divisible-by-k/
* Problem Statement: Given an array of integers and a number K, count the number of pairs of integers in the array whose sum is divisible by K.
* Approach: The solution uses a frequency map (an array `count` of size `k`) to store the frequency of remainders of array elements when divided by `k`. It then iterates from `i = 0` to `k/2` to count the pairs.
* - For `i = 0`, pairs are formed by elements with remainder 0. The number of such pairs is `count[0] * (count[0] - 1) / 2`.
* - For `i` from 1 to `k/2 - 1`, pairs are formed by elements with remainder `i` and `k-i`. The number of such pairs is `count[i] * count[k-i]`.
* - If `k` is even, pairs are formed by elements with remainder `k/2`. The number of such pairs is `count[k/2] * (count[k/2] - 1) / 2`.
* Time Complexity: O(n + k)
* Space Complexity: O(k)
*/
// program to count no of pairs ai, aj that are divisable by k no repetition
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  int k = 4;         // taken k can be inputted
  long long cnt = 0; // Counter for total operations
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<long long> count(k, 0);

    // Reading input and counting remainders: O(n)
    for (int i = 0; i < n; i++) {
      long long num;
      cin >> num;
      count[num % k]++;
      cnt++; // Count each input processing operation
    }

    // Calculating answer: O(k)
    int ans = 0;

    // For rem = 0
    ans += (count[0] * (count[0] - 1)) / 2;
    cnt++; // Count this operation

    // For rem = 1 to (k/2)-1
    for (int i = 1; i <= (k / 2) - 1; i++) {
      ans += count[i] * count[k - i];
      cnt++; // Count each iteration
    }

    // For case k/2
    if (k % 2 == 0) {
      ans += (count[k / 2] * (count[k / 2] - 1)) / 2;
    } else {
      ans += 
          count[k / 2] * count[(k / 2) + 1]; // Fixed: should be multiplication
    }
    cnt++; // Count this operation

    cout << ans << "\n";
  }

  cout << "Total operations count: " << cnt << "\n";
  return 0;
}
