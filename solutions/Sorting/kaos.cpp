/*
Problem: KAOS - Kaos
Link: https://www.spoj.com/problems/KAOS/
Problem Statement: The "chaos degree" of a set of words is the number of pairs of different words (A, B) such that A is lexicographically smaller than B, but reverse(B) is lexicographically smaller than reverse(A). The task is to calculate this chaos degree.
Approach: The problem can be modeled as counting inversions. First, we create a mapping from each word to its rank in the lexicographically sorted list of original words. Then, we create another mapping from each reversed word to its rank in the lexicographically sorted list of reversed words. We then create an array where the i-th element is the rank of the reversed word corresponding to the i-th word in the sorted list of original words. The number of inversions in this array gives the chaos degree. The number of inversions is calculated using a merge sort based algorithm.
Time Complexity: O(N log N), where N is the number of words, dominated by the sorting and inversion counting steps.
Space Complexity: O(N), for storing the words, their positions, and the temporary array for merge sort.
*/

#include <bits/stdc++.h>
using namespace std;

void mergeFunc(vector<long long> &arr, vector<long long> &tmp, int start,
               int mid, int end, long long &cnt) {
  int p1 = start, p2 = mid + 1, c = start;
  while (p1 <= mid && p2 <= end) {
    if (arr[p1] <= arr[p2])
      tmp[c++] = arr[p1++];
    else {
      tmp[c++] = arr[p2++];
      cnt += mid - p1 + 1;
    }
  }
  while (p1 <= mid)
    tmp[c++] = arr[p1++];
  while (p2 <= end)
    tmp[c++] = arr[p2++];
  for (int i = start; i <= end; i++)
    arr[i] = tmp[i];
}

void divideFunc(vector<long long> &arr, vector<long long> &tmp, int start,
                int end, long long &cnt) {
  if (start >= end)
    return;
  int mid = (start + end) / 2;
  divideFunc(arr, tmp, start, mid, cnt);
  divideFunc(arr, tmp, mid + 1, end, cnt);
  mergeFunc(arr, tmp, start, mid, end, cnt);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> words(n);
  for (int i = 0; i < n; i++)
    cin >> words[i];

  // ascending positions
  vector<string> asc = words;
  sort(asc.begin(), asc.end());
  unordered_map<string, int> ascPos;
  for (int i = 0; i < n; i++)
    ascPos[asc[i]] = i;

  // descending positions of reversed words
  vector<string> rev = words;
  for (auto &w : rev)
    reverse(w.begin(), w.end());
  sort(rev.begin(), rev.end());
  unordered_map<string, int> descPos;
  for (int i = 0; i < n; i++)
    descPos[rev[i]] = i;

  // build array
  vector<long long> arr(n), tmp(n);
  for (auto &w : words) {
    string rw = w;
    reverse(rw.begin(), rw.end());
    arr[ascPos[w]] = descPos[rw];
  }

  long long cnt = 0;
  divideFunc(arr, tmp, 0, n - 1, cnt);
  cout << cnt << "\n";
  return 0;
}
