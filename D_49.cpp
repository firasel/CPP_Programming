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
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (root->val > q->val && root->val > p->val && root->left)
      return lowestCommonAncestor(root->left, p, q);
    if (root->val < q->val && root->val < p->val && root->right)
      return lowestCommonAncestor(root->right, p, q);
    return root;
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

  TreeNode *res = st.lowestCommonAncestor(root, node7, node6);
  cout << res->val << endl;

  return 0;
}