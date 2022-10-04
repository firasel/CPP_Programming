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
  bool evaluateTree(TreeNode *root)
  {
    if (root->val > 1)
    {
      if (root->val == 2)
        return evaluateTree(root->left) || evaluateTree(root->right) ? 1 : 0;
      if (root->val == 3)
        return evaluateTree(root->left) && evaluateTree(root->right) ? 1 : 0;
    }
    else
      return root->val;
    return root->val;
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
  TreeNode *mainRoot = new TreeNode(2);
  TreeNode *root1 = new TreeNode(1);
  TreeNode *root2 = new TreeNode(3);
  TreeNode *root3 = new TreeNode(0);
  TreeNode *root4 = new TreeNode(1);
  // TreeNode *root5 = new TreeNode(4);
  // TreeNode *root6 = new TreeNode(7);
  // TreeNode *root7 = new TreeNode(3);
  // TreeNode *root8 = new TreeNode(8);

  mainRoot->left = root1;
  mainRoot->right = root2;
  root2->left = root3;
  root2->right = root4;
  // root1->right = root4;
  // root4->right = root7;
  // root2->left = root5;
  // root2->right = root6;
  // root6->right = root8;

  preOrder(mainRoot);
  cout << endl;
  cout << st.evaluateTree(mainRoot) << endl;
  return 0;
}