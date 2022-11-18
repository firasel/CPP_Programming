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
  void traverseRightSide(TreeNode *root, vector<int> &nums)
  {
    if (!root)
      return;
    nums.push_back(root->val);
    traverseRightSide(root->right, nums);
  }

  vector<int> rightSideView(TreeNode *root)
  {
    vector<int> nums;
    if (!root)
      return nums;
    TreeNode *temp;
    int ans;
    queue<TreeNode *> allNodes;
    allNodes.push(root);
    allNodes.push(NULL);
    while (!allNodes.empty())
    {
      temp = allNodes.front();
      allNodes.pop();
      if (temp)
      {
        ans = temp->val;
        if (!temp->right && temp->left)
          allNodes.push(temp->left);
        if (temp->right)
          allNodes.push(temp->right);
      }
      else
      {
        if (!allNodes.empty())
          allNodes.push(NULL);
        nums.push_back(ans);
      }
    }
    return nums;
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

  vector<int> res = st.rightSideView(root);

  for (auto num : res)
    cout << num << " ";
  cout << endl;
  return 0;
}