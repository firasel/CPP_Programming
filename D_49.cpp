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
  void moveZeroes(vector<int> &nums)
  {
    int k = 0, size = nums.size();
    for (int i = 0; i < size; i++)
      if (nums[i] != 0)
        nums[k++] = nums[i];
    while (k < size)
      nums[k++] = 0;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {0, 1, 0, 3, 12};
  st.moveZeroes(nums);
  for (auto num : nums)
    cout << num << " ";
  cout << endl;
  return 0;
}