/*
Problem: Minimum One Bit Operations to Make Integers Zero
Link: https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
Problem Statement: Given an integer n, you have to find the minimum number of one-bit operations to make it zero. The allowed operations are:
1. Change the rightmost bit.
2. Change the i-th bit if the (i-1)-th bit is 1 and bits from (i-2) to 0 are 0.
Approach: This problem can be solved by understanding its connection to Gray codes. The number of operations required to convert n to 0 is given by the n-th term of a sequence where a(n) = n ^ (n/2) ^ (n/4) ^ ... until n becomes 0. The solution implements this by repeatedly XORing the answer with n and right-shifting n until it becomes 0.
Time Complexity: O(log n)
Space Complexity: O(1)
*/
class Solution {
public:
  int minimumOneBitOperations(int n) {
    int ans = 0;
    while (n) {
      ans ^= n;
      n >>= 1;
    }
    return ans;
  }
};
