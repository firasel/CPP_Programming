#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
  {
    if ((mat.size() * mat[0].size()) != r * c)
      return mat;
    vector<vector<int>> res;
    queue<int> allNums;
    for (auto nums : mat)
      for (auto num : nums)
        allNums.push(num);

    for (int i = 0; i < r; i++)
    {
      vector<int> temp;
      for (int j = 0; j < c; j++)
      {
        temp.push_back(allNums.front());
        allNums.pop();
      }
      res.push_back(temp);
    }
    return res;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> nums = {{1, 2}, {3, 4}};
  vector<vector<int>> res = st.matrixReshape(nums, 1, 4);
  for (auto allNums : res)
  {
    for (auto num : allNums)
      cout << num << " ";
    cout << endl;
  }

  return 0;
}