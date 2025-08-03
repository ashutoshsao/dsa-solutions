#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> nums(n);
    int minNum = INT_MAX, maxNum = INT_MIN;

    for (int i = 0; i < n; ++i) {
      cin >> nums[i];
      minNum = min(minNum, nums[i]);
      maxNum = max(maxNum, nums[i]);
    }

    if (n < 2) {
      cout << 0 << "\n";
      continue;
    }

    if (minNum == maxNum) {
      cout << 0 << "\n";
      continue;
    }

    // Calculate gap using ceil
    int gap = max(1, (int)ceil((double)(maxNum - minNum) / (n - 1)));

    // Calculate bucket count based on gap
    int bucketCount = (maxNum - minNum) / gap + 1;

    vector<int> bucketMin(bucketCount, INT_MAX);
    vector<int> bucketMax(bucketCount, INT_MIN);

    for (int i = 0; i < n; i++) {
      int idx = (nums[i] - minNum) / gap;
      bucketMin[idx] = min(bucketMin[idx], nums[i]);
      bucketMax[idx] = max(bucketMax[idx], nums[i]);
    }

    int ans = 0;
    int prevMax = minNum;

    for (int i = 0; i < bucketCount; ++i) {
      // Check if bucket is empty by checking if bucketMax[i] == INT_MIN
      if (bucketMax[i] == INT_MIN)
        continue;

      ans = max(ans, bucketMin[i] - prevMax);
      prevMax = bucketMax[i];
    }

    cout << ans << "\n";
  }
}
