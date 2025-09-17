/*
Problem: YODANESS - Yodaness Level
Link: https://www.spoj.com/problems/YODANESS/
Problem Statement: The task is to calculate the "yodaness level" of a statement, which is the number of pairs of words that are in a different order compared to the normal version of the statement. This is equivalent to counting the number of inversions between the two sequences of words.
Approach: The solution maps each word in the correct sentence to its original position. Then, it transforms the "Yoda-speak" sentence into a sequence of these positions. The problem is now reduced to counting the number of inversions in this new sequence. The solution uses a classic merge sort algorithm to count these inversions efficiently.
Time Complexity: O(N log N), where N is the number of words, due to the merge sort algorithm.
Space Complexity: O(N) for storing the word-to-position map and the temporary array used in merge sort.
*/
#include <bits/stdc++.h>
using namespace std;

void mergeFunc(vector<long long> &arr, vector<long long> &tmp, int start, int m, int end, long long &cnt) {
  int p1 = start, p2 = m + 1, c = start;
  while (p1 <= m && p2 <= end) {
    if (arr[p1] <= arr[p2])
      tmp[c++] = arr[p1++];
    else {
      tmp[c++] = arr[p2++];
      cnt += m - p1 + 1;
    }
  }
  while (p1 <= m) {
    tmp[c++] = arr[p1++];
  }
  while (p2 <= end) {
    tmp[c++] = arr[p2++];
  }
  for (int i = start; i <= end; i++) {
    arr[i] = tmp[i];
  }
}

void divideFunc(vector<long long> &arr, vector<long long> &tmp, int start, int end, long long &cnt) {
  if (start == end)
    return;

  int m = (start + end) / 2;
  divideFunc(arr, tmp, start, m, cnt);
  divideFunc(arr, tmp, m + 1, end, cnt);
  mergeFunc(arr, tmp, start, m, end, cnt);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<string> yoda(n), correct(n);
    for (int i = 0; i < n; i++)
      cin >> yoda[i];
    for (int i = 0; i < n; i++)
      cin >> correct[i];

    // Map each word in correct sentence to its position
    unordered_map<string, int> pos;
    for (int i = 0; i < n; i++)
      pos[correct[i]] = i;

    // Convert Yoda sentence into an array of positions
    vector<long long> arr(n), tmp(n);
    for (int i = 0; i < n; i++) {
      arr[i] = pos[yoda[i]];
    }

    long long cnt = 0;
    divideFunc(arr, tmp, 0, n - 1, cnt);
    cout << cnt << "\n";
  }
  return 0;
}
