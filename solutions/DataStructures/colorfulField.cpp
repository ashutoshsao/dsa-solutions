#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, k, t;
  cin >> n >> m >> k >> t;

  set<long long> wasteSet;       // for O(log k) lookup
  vector<long long> wasteSorted; // to count waste before index

  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    long long idx = 1LL * (x - 1) * m + (y - 1); // Flattened 1D index
    wasteSet.insert(idx);
    wasteSorted.push_back(idx);
  }

  sort(wasteSorted.begin(), wasteSorted.end()); // To count earlier waste cells

  vector<string> crops = {"Carrots", "Kiwis", "Grapes"};

  while (t--) {
    int x, y;
    cin >> x >> y;
    long long idx = 1LL * (x - 1) * m + (y - 1);

    if (wasteSet.count(idx)) {
      cout << "Waste\n";
    } else {
      // Count how many waste cells come before this index
      int wasteBefore = 0;
      for (long long w : wasteSorted) {
        if (w < idx)
          wasteBefore++;
        else
          break;
      }

      int adjustedIndex = (idx - wasteBefore) % 3;
      cout << crops[adjustedIndex] << "\n";
    }
  }
}
