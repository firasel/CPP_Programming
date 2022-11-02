#include <bits/stdc++.h>

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

class Solution
{
public:
  bool isValidBST(TreeNode *root, long low = LONG_MIN, long high = LONG_MAX)
  {
    return !root || (root->val > low && root->val < high && isValidBST(root->left, low, root->val) && isValidBST(root->right, root->val, high));
  }
};

int main()
{
  Solution st;
  TreeNode *root = new TreeNode(6);
  TreeNode *node1 = new TreeNode(2);
  TreeNode *node2 = new TreeNode(8);
  TreeNode *node3 = new TreeNode(0);
  TreeNode *node4 = new TreeNode(4);
  TreeNode *node5 = new TreeNode(7);
  TreeNode *node6 = new TreeNode(9);
  TreeNode *node7 = new TreeNode(3);
  TreeNode *node8 = new TreeNode(5);

  root->left = node1;
  root->right = node2;
  node1->left = node3;
  node1->right = node4;
  node4->left = node7;
  node4->right = node8;

  node2->left = node5;
  node2->right = node6;

  bool res = st.isValidBST(root);
  cout << res << endl;

  return 0;
}