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
  vector<int> sortedSquares(vector<int> &nums)
  {
    int size = nums.size();
    for (int i = 0; i < size; i++)
      if (nums[i] < 0)
        nums[i] = abs(nums[i]);
    sort(nums.begin(), nums.end());
    for (int i = 0; i < size; i++)
      nums[i] = nums[i] * nums[i];
    return nums;
  }
};

int main()
{
  Solution st;
  // TreeNode *root = new TreeNode(3);
  // TreeNode *n2 = new TreeNode(1);
  // TreeNode *n3 = new TreeNode(4);
  // TreeNode *n4 = new TreeNode(2);

  // root->left = n2;
  // root->right = n3;
  // n2->right = n4;
  vector<int> nums = {-7, -3, 2, 3, 11};
  vector<int> res = st.sortedSquares(nums);
  for (auto num : res)
    cout << num << endl;
  return 0;
}