#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<double>> pyramid;

void pour(int i, int j, double t) {
  // Base case: if no liquid to pour or we've reached beyond the pyramid
  if (t <= 0 || i >= n) {
    return; // No liquid or spills to floor (lost)
  }

  // Add liquid to current glass
  pyramid[i][j] += t;

  // If glass overflows and not at bottom level
  if (pyramid[i][j] > 1.0 && i < n - 1) {
    double overflow = pyramid[i][j] - 1.0;
    pyramid[i][j] = 1.0; // Keep glass exactly full

    // Recursively pour overflow to glasses below
    pour(i + 1, j, overflow / 2.0);     // Left glass below
    pour(i + 1, j + 1, overflow / 2.0); // Right glass below
  }
  // If glass overflows at bottom level, overflow is lost (do nothing)
  else if (pyramid[i][j] > 1.0) {
    pyramid[i][j] = 1.0; // Keep glass exactly full, lose overflow
  }
}

int main() {
  int t;
  cin >> n >> t;

  // Initialize pyramid
  pyramid.resize(n);
  for (int i = 0; i < n; i++) {
    pyramid[i].resize(i + 1, 0.0);
  }

  // Start pouring from top glass
  pour(0, 0, (double)t);

  // Count full glasses
  int fullGlasses = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if (pyramid[i][j] >= 1.0 - 1e-9) { // Account for floating point precision
        fullGlasses++;
      }
    }
  }

  cout << fullGlasses << endl;

  return 0;
}
