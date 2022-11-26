#include <bits/stdc++.h>
#include <iostream>
#include <numeric>

using namespace std;

class TreeNode
{
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val)
  {
    this->val = val;
    left = NULL;
    right = NULL;
  }
};

void printTree(TreeNode *root)
{
  if (root == NULL)
    return;
  cout << root->val << " ";
  printTree(root->left);
  printTree(root->right);
};

class Solution
{
public:
  int numberOfCuts(int n)
  {
    if (n < 2)
      return 0;
    if (n % 2 == 0)
      return n / 2;
    return n;
  }
  vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> ans(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
      int oneRow = 0, zeroRow = 0;
      for (int j = 0; j < n; j++)
        if (grid[i][j] == 1)
          oneRow++;
        else
          zeroRow++;
      for (int j = 0; j < n; j++)
      {
        int oneCol = 0, zeroCol = 0;
        for (int k = 0; k < m; k++)
          if (grid[k][j] == 1)
            oneCol++;
          else
            zeroCol++;

        ans[i][j] = oneRow + oneCol - zeroRow - zeroCol;
      }
    }
    return ans;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> nums = {{0, 1, 1}, {1, 0, 1}, {0, 0, 1}};
  vector<vector<int>> res = st.onesMinusZeros(nums);
  for (auto nums : res)
  {
    for (auto num : nums)
      cout << num << " ";
    cout << endl;
  }
  return 0;
}