#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isValidSudoku(vector<vector<char>> &board)
  {
    map<char, int> freq;
    // Row valid check
    for (int i = 0; i < 9; i++)
    {
      for (auto ch : board[i])
      {
        if (ch != '.')
        {
          freq[ch]++;
          if (freq[ch] > 1)
            return false;
        }
      }
      freq.clear();
    }
    // Col valid check
    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
      {
        if (board[j][i] != '.')
        {
          freq[board[j][i]]++;
          if (freq[board[j][i]] > 1)
            return false;
        }
      }
      freq.clear();
    }
    // Cube valid check
    int jLim = 3, kLim = 3, count = 0;
    for (int i = 0; i < 9; i++)
    {
      for (int j = jLim - 3; j < jLim; j++)
      {
        for (int k = kLim - 3; k < kLim; k++)
        {
          cout << board[j][k] << " ";
          if (board[j][k] != '.')
          {
            freq[board[j][k]]++;
            if (freq[board[j][k]] > 1)
              return false;
          }
        }
        cout << endl;
      }
      cout << endl
           << endl;
      count++;
      if (count == 3)
      {
        count = 0;
        jLim += 3;
      }
      if (kLim >= 9)
      {
        kLim = 0;
      }
      kLim += 3;
      freq.clear();
    }
    return true;
  }
};

int main()
{
  Solution st;
  vector<vector<char>> board =
      {
          {'.', '.', '4', '.', '.', '.', '6', '3', '.'},
          {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
          {'5', '.', '.', '.', '.', '.', '.', '9', '.'},
          {'.', '.', '.', '5', '6', '.', '.', '.', '.'},
          {'4', '.', '3', '.', '.', '.', '.', '.', '1'},
          {'.', '.', '.', '7', '.', '.', '.', '.', '.'},
          {'.', '.', '.', '5', '.', '.', '.', '.', '.'},
          {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
          {'.', '.', '.', '.', '.', '.', '.', '.', '.'}};
  bool res = st.isValidSudoku(board);
  cout << res << endl;

  return 0;
}