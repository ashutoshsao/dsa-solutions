/*
 * Problem: Equivalent Sub-Arrays
 * Link: https://www.geeksforgeeks.org/problems/equivalent-sub-arrays3731/1
 * Problem Statement: Given an array arr[] of n integers, the task is to count the total number of subarrays that have the same number of distinct elements as the original array.
 * Approach: The solution uses a sliding window (two-pointer) approach. It calculates the number of subarrays with at most k distinct elements and then uses this to find the number of subarrays with exactly k distinct elements. The number of subarrays with exactly k distinct elements is atMostK(k) - atMostK(k-1). In this problem, k is the total number of distinct elements in the original array.
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */
class Solution {
public:
  int atMostKDistinct(int arr[], int n, int k) {
    unordered_map<int, int> freq;
    long long count = 0;
    int i = 0;
    for (int j = 0; j < n; j++) {
      freq[arr[j]]++;

      while ((int)freq.size() > k) {
        freq[arr[i]]--;
        if (freq[arr[i]] == 0)
          freq.erase(arr[i]);
        i++;
      }

      count += (j - i + 1);
    }

    return count;
  }

  int countDistinctSubarray(int arr[], int n) {
    unordered_set<int> st(arr, arr + n);
    int totalDistinct = st.size();

    return atMostKDistinct(arr, n, totalDistinct) -
           atMostKDistinct(arr, n, totalDistinct - 1);
  }
};

int main() {
  vector<int> arr = {2, 1, 3, 2, 3};
  int n = nums.size();
  Solution sol;
  int ans = sol.countDistinctSubarray(arr, n);
  cout << ans << "\n";
}
