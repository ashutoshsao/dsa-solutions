/*
 * Problem: Group Anagrams
 * Link: https://leetcode.com/problems/group-anagrams/
 * Problem Statement: Given an array of strings, group the anagrams together. Anagrams are strings that have the same characters with the same frequencies.
 * Approach: The solution uses a hash map to group anagrams. For each string, it calculates a frequency map of its characters, which is then converted into a unique key. This key is used to store the string in the hash map. All strings that are anagrams of each other will produce the same key and thus be grouped together.
 * Time Complexity: O(N*K), where N is the number of strings and K is the maximum length of a string.
 * Space Complexity: O(N*K) in the worst case, where all strings are unique.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> mp;
    for (string s : strs) {
      vector<int> freq(26, 0);
      for (char c : s) {
        freq[c - 'a']++;
      }
      string key = "";
      for (int x : freq) {
        key += to_string(x) + "#";
      }
      mp[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto &x : mp) {
      result.push_back(move(x.second));
    }
    return result;
  }
};
