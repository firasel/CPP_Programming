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
  printTree(root->left);
  cout << root->val << " ";
  printTree(root->right);
};

class Solution
{
public:
  int rangeSumBST(TreeNode *root, int low, int high, int sum = 0)
  {
    if (!root)
      return 0;
    return ((root->val >= low && root->val <= high) ? root->val : 0) + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
  }
};

int main()
{
  Solution st;
  TreeNode *root = new TreeNode(10);
  TreeNode *val1 = new TreeNode(5);
  TreeNode *val2 = new TreeNode(15);
  TreeNode *val3 = new TreeNode(3);
  TreeNode *val4 = new TreeNode(7);
  TreeNode *val5 = new TreeNode(18);

  root->left = val1;
  root->right = val2;
  val1->left = val3;
  val1->right = val4;
  val2->right = val5;

  printTree(root);
  cout << endl;

  int res = st.rangeSumBST(root, 7, 15);
  cout << res << endl;
  return 0;
}