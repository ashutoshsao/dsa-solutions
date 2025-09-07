/*
Problem: Maximum Weight Difference
Link: https://www.codechef.com/problems/MAXDIFF
Problem Statement: Given N items with their weights and an integer K, the items are to be split into two groups, one with K items and the other with N-K items. Chef takes the heavier group and his son takes the lighter one. Find the maximum possible difference between the weight carried by Chef and his son.
Approach: To maximize the difference between the weights of the two groups, we should make one group as light as possible and the other as heavy as possible. The total weight is fixed. Let the sum of weights of the two groups be S1 and S2. The difference is |S1 - S2|. Let Total = S1 + S2. Then S2 = Total - S1. The difference is |S1 - (Total - S1)| = |2*S1 - Total|. To maximize this, S1 should be minimized or maximized.
We can choose to give the son either K items or N-K items. To make his share minimum, we should give him the min(K, N-K) lightest items.
So, we sort the weights in ascending order and calculate the sum of the first min(K, N-K) weights. This is the son's total weight. The remaining weight is for the chef. The difference is (Total - son's_weight) - son's_weight.
Time Complexity: O(N log N) for sorting the weights.
Space Complexity: O(N) to store the weights.
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    nums.reserve(n);
    long long total = 0;
    for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      nums.push_back(num);
      total += num;
    }
    sort(nums.begin(), nums.end());
    long long child = 0;
    int items_for_child = min(k, n - k);
    for (int i = 0; i < items_for_child; i++) {
      child += nums[i];
    }
    cout << (total - child) - child << "\n";
  }
}
