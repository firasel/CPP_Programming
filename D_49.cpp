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
  void inOrder(TreeNode *root, int k, int &cnt, int &ans)
  {
    if (!root && cnt > k)
      return;
    if (root->left)
      inOrder(root->left, k, cnt, ans);
    cnt++;
    if (k == cnt)
      ans = root->val;
    if (root->right)
      inOrder(root->right, k, cnt, ans);
  }

  int kthSmallest(TreeNode *root, int k)
  {
    int ans, cnt = 0;
    inOrder(root, k, cnt, ans);
    return ans;
  }
};

int main()
{
  Solution st;
  TreeNode *root = new TreeNode(3);
  TreeNode *n2 = new TreeNode(1);
  TreeNode *n3 = new TreeNode(4);
  TreeNode *n4 = new TreeNode(2);

  root->left = n2;
  root->right = n3;
  n2->right = n4;

  int res = st.kthSmallest(root, 3);

  cout << res << endl;
  return 0;
}