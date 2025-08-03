#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

// Function to calculate GCD of multiple numbers (including duplicates)
int gcdOfVector(const vector<int> &frequencies) {
  if (frequencies.empty())
    return 0;

  auto result = frequencies[0];
  for (auto it = frequencies.begin() + 1; it != frequencies.end(); ++it) {
    result = gcd(result, *it);
    if (result == 1)
      break; // Early termination if GCD becomes 1
  }
  return result;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto it = arr.begin(); it != arr.end(); ++it) {
      cin >> *it;
    }

    // Calculate frequencies using map
    map<int, int> freqMap;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
      freqMap[*it]++;
    }

    // Store frequencies in a vector (keeps duplicates)
    vector<int> frequencies;
    for (auto it = freqMap.begin(); it != freqMap.end(); ++it) {
      frequencies.push_back(it->second);
    }

    // Calculate GCD of all frequencies
    auto result = gcdOfVector(frequencies);

    // Check if GCD >= 2
    if (result >= 2) {
      cout << "true\n";
    } else {
      cout << "false\n";
    }
  }

  return 0;
}
