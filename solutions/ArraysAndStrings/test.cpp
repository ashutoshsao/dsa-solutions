#include <bits/stdc++.h>

#include <climits>

using namespace std;

int main() {

  int t;

  cin >> t;

  while (t--) {

    int n;

    cin >> n;

    vector<int> v(n);

    int numMin = INT_MAX;

    int numMax = INT_MIN;

    for (int i = 0; i < n; i++) {

      cin >> v[i];

      numMin = min(numMin, v[i]);

      numMax = max(numMax, v[i]);
    }

    if (n < 2) {

      cout << 0 << '\n';

      continue;
    }

    if (numMax == numMin) {

      cout << 0 << '\n';

      continue;
    }

    // calculating minimum Gap

    int minGap = max(1, (int)ceil((double)(numMax - numMin) / (n - 1)));

    // calculating number of buckets

    int bucketCount = ((numMax - numMin) / minGap) + 1;

    // declaring min an max array to store min and max of each bucket

    vector<int> vMin(bucketCount, INT_MAX);

    vector<int> vMax(bucketCount, INT_MIN);

    for (int i = 0; i < n; i++) {

      int idx = (v[i] - numMin) / minGap;

      vMin[idx] = min(vMin[idx], v[i]);

      vMax[idx] = max(vMax[idx], v[i]);
    }

    int ans = 0;

    int prevMax = numMin;

    for (int i = 0; i < bucketCount; i++) {

      if (vMax[i] == INT_MIN)

        continue;

      ans = max(vMin[i] - prevMax, ans);

      prevMax = vMax[i];
    }

    cout << ans << '\n';
  }
}
