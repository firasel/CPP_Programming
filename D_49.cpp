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
  void inOrder(TreeNode *root, int k, vector<int> &nums)
  {
    if (!root && k == nums.size())
      return;
    if (root->left)
      inOrder(root->left, k, nums);
    nums.push_back(root->val);
    if (root->right)
      inOrder(root->right, k, nums);
  }

  int kthSmallest(TreeNode *root, int k)
  {
    vector<int> nums;
    inOrder(root, k, nums);
    return nums[k - 1];
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