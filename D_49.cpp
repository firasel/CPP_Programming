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
  int chalkReplacer(vector<int> chalk, int k)
  {
    int size = chalk.size(), i;
    long long sum = 0;
    sum = accumulate(chalk.begin(), chalk.end(), sum);
    k %= sum;
    for (i = 0; i < size; i++)
    {
      if (chalk[i] <= k)
        k -= chalk[i];
      else
        return i;
    }
    if (i == size)
      i = 0;
    return i;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {3, 4, 1, 2};
  int res = st.chalkReplacer(nums, 25);
  cout << res << endl;
  return 0;
}