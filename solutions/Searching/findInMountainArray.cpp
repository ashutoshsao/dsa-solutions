/*
 * Problem: Find in Mountain Array
 * Link: https://leetcode.com/problems/find-in-mountain-array/description/
 * Problem Statement: You are given a mountain array, which is an array that first increases to a peak and then decreases. You cannot access the array directly but must use a MountainArray interface with get(index) and length() methods. The goal is to find the minimum index where the element equals a given target value. If the target does not exist in the array, you should return -1.
 * Approach: The solution first finds the peak of the mountain array using a modified binary search. Then, it performs two separate binary searches for the target value: one on the increasing part of the array (from the start to the peak) and another on the decreasing part (from the peak to the end). If the target is found, the function returns the index; otherwise, it returns -1.
 * Time Complexity: O(log n), where n is the number of elements in the mountain array. This is because finding the peak takes O(log n) time, and the two subsequent binary searches also take O(log n) time.
 * Space Complexity: O(1), as the solution uses a constant amount of extra space.
 */

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
  int findInMountainArray(int target, MountainArray &mountainArr)
  {
    int n = mountainArr.length();

    // 1. find peak
    int left = 0, right = n - 1;
    while (left < right)
    {
      int mid = left + (right - left) / 2;
      if (mountainArr.get(mid) < mountainArr.get(mid + 1))
        left = mid + 1; // peak at right side
      else
        right = mid; // peak could be mid
    }
    int peak = left;

    // 2. binary search target in 0 ... peak
    int ans = binarySearch(mountainArr, target, 0, peak, true);
    if (ans != -1)
      return ans;

    // 2. binary search target in peak+1 ... n-1
    return binarySearch(mountainArr, target, peak + 1, n - 1, false);
  }

private:
  int binarySearch(MountainArray &mountainArr, int target, int left, int right, bool asc)
  {
    while (left <= right)
    {

      int mid = left + (right - left) / 2;
      int val = mountainArr.get(mid);

      if (val == target)
        return mid;

      if (asc)
      {
        if (val < target)
          left = mid + 1;
        else
          right = mid - 1;
      }
      else
      {
        if (val > target)
          left = mid + 1;
        else
          right = mid - 1;
      }
    }
    return -1;
  }
};
