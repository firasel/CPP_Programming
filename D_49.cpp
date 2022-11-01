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
  vector<int> nums;
  void preOrderTraverse(TreeNode *root)
  {
    if (root == NULL)
      return;
    preOrderTraverse(root->left);
    nums.push_back(root->val);
    preOrderTraverse(root->right);
  }

  bool findTargetSum(int start, int end, int target)
  {
    bool result = false;
    if (start >= end)
      return result;
    if (nums[end] < target / 2)
      return result;
    int res = nums[start] + nums[end];
    if (res == target)
      return true;
    if (res > target)
      return findTargetSum(start, end - 1, target);
    if (res < target)
      return findTargetSum(start + 1, end, target);
    return result;
  }

  bool findTarget(TreeNode *root, int k)
  {
    nums.clear();
    preOrderTraverse(root);
    return findTargetSum(0, nums.size() - 1, k);
  }
};

int main()
{
  Solution st;
  TreeNode *root = new TreeNode(5);
  TreeNode *node1 = new TreeNode(3);
  TreeNode *node2 = new TreeNode(6);
  TreeNode *node3 = new TreeNode(2);
  TreeNode *node4 = new TreeNode(4);
  TreeNode *node5 = new TreeNode(7);

  root->left = node1;
  root->right = node2;
  node1->left = node3;
  node1->right = node4;
  node2->right = node5;

  bool res = st.findTarget(root, 9);
  cout << res << endl;

  return 0;
}