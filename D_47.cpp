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
  TreeNode *bstToGstHelper(TreeNode *root, int &val)
  {
    if (root == NULL)
      return root;
    bstToGstHelper(root->right, val);
    root->val = root->val + val;
    val = root->val;
    bstToGstHelper(root->left, val);
    return root;
  }

  TreeNode *bstToGst(TreeNode *root)
  {
    if (root == NULL)
      return root;
    int sum = 0;
    return bstToGstHelper(root, sum);
  }
};

void preOrder(TreeNode *root)
{
  if (root == NULL)
    return;
  cout << root->val << " ";
  preOrder(root->left);
  preOrder(root->right);
}

int main()
{
  Solution st;
  TreeNode *mainRoot = new TreeNode(4);
  TreeNode *root1 = new TreeNode(1);
  TreeNode *root2 = new TreeNode(6);
  TreeNode *root3 = new TreeNode(0);
  TreeNode *root4 = new TreeNode(2);
  TreeNode *root5 = new TreeNode(5);
  TreeNode *root6 = new TreeNode(7);
  TreeNode *root7 = new TreeNode(3);
  TreeNode *root8 = new TreeNode(8);

  mainRoot->left = root1;
  mainRoot->right = root2;
  root1->left = root3;
  root1->right = root4;
  root4->right = root7;
  root2->left = root5;
  root2->right = root6;
  root6->right = root8;

  preOrder(mainRoot);
  cout << endl;
  TreeNode *root = st.bstToGst(mainRoot);
  cout << endl;
  preOrder(root);
  return 0;
}