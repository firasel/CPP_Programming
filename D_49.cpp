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

void printTree(TreeNode *root, string &str)
{
  if (root == NULL)
  {
    str += "NULL_";
    return;
  }
  cout << root->val << " ";
  str += to_string(root->val) + '_';
  printTree(root->left, str);
  printTree(root->right, str);
};

class Solution
{
public:
  void targetSumFind(TreeNode *root, vector<int> nums, vector<vector<int>> &res, int sum, int targetSum)
  {
    if (!root)
      return;
    nums.push_back(root->val);
    sum += root->val;
    if (!root->left && !root->right && sum == targetSum)
    {
      res.push_back(nums);
      return;
    }
    targetSumFind(root->left, nums, res, sum, targetSum);
    targetSumFind(root->right, nums, res, sum, targetSum);
  }
  vector<vector<int>> pathSum(TreeNode *root, int targetSum)
  {
    vector<int> nums;
    vector<vector<int>> res;
    targetSumFind(root, nums, res, 0, targetSum);
    return res;
  }
};

int main()
{
  Solution st;
  TreeNode *root = new TreeNode(1);
  TreeNode *n2 = new TreeNode(2);
  TreeNode *n3 = new TreeNode(3);
  TreeNode *n4 = new TreeNode(5);
  TreeNode *n5 = new TreeNode(4);

  root->left = n2;
  root->right = n3;
  n2->right = n4;
  n3->right = n5;

  vector<vector<int>> res = st.pathSum(root, 8);

  for (auto nums : res)
  {
    for (auto num : nums)
      cout << num << " ";
    cout << endl;
  }
  return 0;
}