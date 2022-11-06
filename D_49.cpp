#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> generateMatrix(int n)
  {
    int cnt = 1, top = 0, right = n - 1, bottom = n - 1, left = 0;
    vector<vector<int>> res(n, vector<int>(n, 1));
    while (top <= bottom && left <= right)
    {
      for (int i = left; i <= right; i++)
      {
        res[top][i] = cnt++;
      }
      top++;

      for (int i = top; i <= bottom; i++)
      {
        res[i][right] = cnt++;
      }
      right--;

      for (int i = right; i >= left; i--)
      {
        res[bottom][i] = cnt++;
      }
      bottom--;

      for (int i = bottom; i >= top; i--)
      {
        res[i][left] = cnt++;
      }
      left++;
    }
    return res;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> res = st.generateMatrix(4);
  for (auto nums : res)
  {
    for (auto num : nums)
      cout << num << " ";
    cout << endl;
  }

  return 0;
}