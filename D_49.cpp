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
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (!root || root == p || root == q)
      return root;
    TreeNode *root1 = lowestCommonAncestor(root->left, p, q);
    TreeNode *root2 = lowestCommonAncestor(root->right, p, q);
    if (root1 && root2)
      return root;
    return root1 ? root1 : root2;
  }
};

int main()
{
  Solution st;
  TreeNode *root = new TreeNode(3);
  TreeNode *n2 = new TreeNode(5);
  TreeNode *n3 = new TreeNode(1);
  TreeNode *n4 = new TreeNode(6);
  TreeNode *n5 = new TreeNode(2);
  TreeNode *n6 = new TreeNode(0);
  TreeNode *n7 = new TreeNode(8);
  TreeNode *n8 = new TreeNode(7);
  TreeNode *n9 = new TreeNode(4);

  root->left = n2;
  root->right = n3;
  n2->left = n4;
  n2->right = n5;
  n3->left = n6;
  n3->right = n7;
  n5->left = n8;
  n5->right = n9;

  TreeNode *res = st.lowestCommonAncestor(root, n2, n3);
  cout << res->val << endl;
  return 0;
}