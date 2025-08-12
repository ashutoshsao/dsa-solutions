/*
 * Problem: Word Boggle
 * Link: https://www.geeksforgeeks.org/problems/word-boggle4143/1
 * Problem Statement: Given a dictionary of words and a board of characters, find all words from the dictionary that can be formed by a sequence of adjacent characters on the board.
 * Approach: The solution iterates through each word in the dictionary and searches for it on the board. The search is done using a backtracking approach. For each word, it tries to find the first character on the board. Once found, it explores the 8 adjacent cells to find the next character of the word. A `isVisited` matrix is used to keep track of the cells used in the current path to avoid reusing the same cell for the same word.
 * Time Complexity: O(N * W * L), where N is the number of words in the dictionary, W is the average length of a word, and L is the number of cells on the board. In the worst case, for each word, we might have to search the entire board.
 * Space Complexity: O(M * N) for the `isVisited` matrix, where M and N are the dimensions of the board.
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // 8 possible directions
  int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

  bool getWords(vector<vector<char>> &board, int x, int y, string &word, int index, vector<vector<bool>> &isVisited)
  {
    if (index == word.size())
      return true;

    // boundaries check
    if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
      return false;

    if (isVisited[x][y] || board[x][y] != word[index])
      return false;

    isVisited[x][y] = true;

    // explore all 8 directions
    for (int dir = 0; dir < 8; dir++)
    {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (getWords(board, nx, ny, word, index + 1, isVisited))
      {
        isVisited[x][y] = false;
        return true;
      }
    }

    isVisited[x][y] = false;
    return false;
  }

  vector<string> wordBoggle(vector<vector<char>> &board, vector<string> &dictionary)
  {
    int m = board.size();
    int n = board[0].size();
    vector<string> result;

    for (string &word : dictionary)
    {
      bool found = false;
      vector<vector<bool>> isVisited(m, vector<bool>(n, false));

      for (int i = 0; i < m && !found; i++)
      {
        for (int j = 0; j < n && !found; j++)
        {
          if (board[i][j] == word[0] && getWords(board, i, j, word, 0, isVisited))
          {
            result.push_back(word);
            found = true;
          }
        }
      }
    }

    sort(result.begin(), result.end());
    return result;
  }
};
int main()
{
  vector<vector<char>> board = {{'G', 'I', 'Z'}, {'U', 'E', 'K'}, {'Q', 'S', 'E'}};
  vector<string> dict = {"GEEKS", "FOR", "QUIZ", "GO"};

  Solution obj;
  vector<string> ans = obj.wordBoggle(board, dict);

  for (auto &w : ans)
    cout << w << " ";
  cout << endl;
}
