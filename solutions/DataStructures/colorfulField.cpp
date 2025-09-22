/*
Problem: Colorful Field
Link: https://codeforces.com/problemset/problem/79/B
Problem Statement: A rectangular field of size n x m is divided into 1x1 cells. Some of these cells are waste cells. The remaining cells are cultivated with crops. The crops are planted in the order: Carrots, Kiwis, Grapes, Carrots, Kiwis, Grapes, and so on. The cells are numbered from 1 to n*m, row by row. Given the coordinates of some cells, you need to determine what is planted in them.
Approach: The solution uses a set to store the waste cells for efficient lookup. The 2D coordinates are flattened into a 1D index. For each query, it checks if the cell is in the waste set. If not, it calculates the number of waste cells that appear before the current cell. This is done by iterating through a sorted vector of waste cells. The adjusted index is then used to determine the crop type using the modulo operator.
Time Complexity: O(k log k + t * k), where k is the number of waste cells and t is the number of queries. Sorting the waste cells takes O(k log k). Each query takes O(k) in the worst case to count the number of waste cells before it.
Space Complexity: O(k) to store the waste cells.
*/
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
