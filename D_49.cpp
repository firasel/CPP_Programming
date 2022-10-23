#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> res;
    for (int i = 0; i < numRows; i++)
    {
      vector<int> temp;
      for (int j = 0; j <= i; j++)
      {
        if (j == 0 || j == i)
          temp.push_back(1);
        else
          temp.push_back(res[i - 1][j - 1] + res[i - 1][j]);
      }
      res.push_back(temp);
    }
    return res;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> res = st.generate(10);
  for (auto allNums : res)
  {
    for (auto num : allNums)
      cout << num << " ";
    cout << endl;
  }

  return 0;
}