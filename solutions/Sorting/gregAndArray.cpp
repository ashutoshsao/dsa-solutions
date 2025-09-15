/*
Problem: A. Greg and Array
Link: https://codeforces.com/problemset/problem/295/A
Problem Statement:
Greg has an array 'a' of 'n' integers and 'm' operations. Each operation is defined by (li, ri, di), meaning all elements from index li to ri (1-indexed) should be increased by di. Greg also has 'k' queries. Each query is defined by (xi, yi), meaning operations from index xi to yi (1-indexed) should be applied to the array 'a'. The task is to find the final state of array 'a' after all 'k' queries are executed.

Approach:
This problem involves range updates and can be efficiently solved using difference arrays.
1.  **Count Operation Applications:** First, determine how many times each of the 'm' operations is applied. We can use a difference array (let's call it `op_counts`) for this. For each query (xi, yi), increment `op_counts[xi-1]` by 1 and decrement `op_counts[yi]` by 1 (adjusting for 0-indexed arrays). After processing all 'k' queries, compute the prefix sums of `op_counts` to get the total number of times each operation is applied.
2.  **Calculate Total Changes per Index:** Create another difference array (let's call it `array_diff`). Iterate through the 'm' operations. For each operation `i` (with parameters li, ri, di) and its calculated application count `count_i`, the effective change to the original array `a` is `di * count_i`. Apply this effective change to the `array_diff` array: increment `array_diff[li-1]` by `di * count_i` and decrement `array_diff[ri]` by `di * count_i`.
3.  **Apply Total Changes to Array 'a':** Compute the prefix sums of `array_diff`. Add these prefix sums to the original array `a` to get the final state of the array.

Time Complexity: O(N + M + K)
-   Reading input: O(N + M + K)
-   Processing 'k' queries to count operation applications: O(K) for updates, O(M) for prefix sums. Total O(M + K).
-   Processing 'm' operations to calculate total changes: O(M) for updates.
-   Applying total changes to array 'a': O(N) for prefix sums and final addition.
Overall: O(N + M + K)

Space Complexity: O(N + M)
-   O(N) for the initial array 'a' and the final difference array `array_diff`.
-   O(M) for storing operations and the `op_counts` difference array.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long; // because values can be large

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<ll> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  vector<int> l(m + 1), r(m + 1);
  vector<ll> d(m + 1);
  for (int i = 1; i <= m; i++)
    cin >> l[i] >> r[i] >> d[i];

  vector<ll> opCount(m + 2, 0);
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    opCount[x] += 1;
    opCount[y + 1] -= 1;
  }

  // Prefix sum to get how many times each operation is applied
  for (int i = 1; i <= m; i++)
    opCount[i] += opCount[i - 1];

  vector<ll> arr(n + 2, 0);
  for (int i = 1; i <= m; i++) {
    arr[l[i]] += d[i] * opCount[i];
    arr[r[i] + 1] -= d[i] * opCount[i];
  }

  // Prefix sum to get final increments for each element
  for (int i = 1; i <= n; i++) {
    arr[i] += arr[i - 1];
    a[i] += arr[i];
  }

  for (int i = 1; i <= n; i++)
    cout << a[i] << " ";
  cout << "\n";

  return 0;
}
