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
};

int main()
{
  Solution st;
  vector<int> nums = {2, 2, 3, 4};
  int res = st.numberOfCuts(6);
  cout << res << endl;
  return 0;
}