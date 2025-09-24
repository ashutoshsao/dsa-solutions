/*
Problem: Intersection of Two Arrays
Link: https://leetcode.com/problems/intersection-of-two-arrays/description/
Problem Statement: Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
Approach: The solution first sorts both input arrays. Then, it uses a two-pointer approach to find common elements. Pointers p1 and p2 traverse nums1 and nums2 respectively. If the elements at the pointers are the same, the element is added to the result, and both pointers are advanced past all occurrences of that element. If the elements are different, the pointer pointing to the smaller element is advanced.
Time Complexity: O(m*log(m) + n*log(n)) due to sorting.
Space Complexity: O(k) where k is the number of elements in the intersection.
*/
class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size();
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> result;
    int p1 = 0, p2 = 0;

    while (p1 < m && p2 < n) {
      if (nums1[p1] > nums2[p2])
        p2++;
      else if (nums1[p1] < nums2[p2])
        p1++;
      else {
        int x = nums1[p1];
        result.push_back(x);
        while (p1 < m && nums1[p1] == x)
          p1++;
        while (p2 < n && nums2[p2] == x)
          p2++;
      }
    }
    return result;
  }
};
