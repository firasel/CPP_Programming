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
    vector<int> oneRow(m, 0), oneCol(n, 0), zeroRow(m, 0), zeroCol(n, 0);
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {
          oneRow[i] += 1;
          oneCol[j] += 1;
        }
        if (grid[i][j] == 0)
        {
          zeroRow[i] += 1;
          zeroCol[j] += 1;
        }
      }
    }

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
        grid[i][j] = oneRow[i] + oneCol[j] - zeroRow[i] - zeroCol[j];
    }
    return grid;
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