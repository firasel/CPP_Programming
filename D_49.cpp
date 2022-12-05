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
  vector<int> sortArrayByParity(vector<int> &nums)
  {
    int size = nums.size();
    for (int i = 0, j = 0; i < size; i++)
      if (nums[i] % 2 == 0)
        swap(nums[j++], nums[i]);
    return nums;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {0, 1, 0, 3, 12};
  vector<int> res = st.sortArrayByParity(nums);
  for (auto num : res)
    cout << num << " ";
  cout << endl;
  return 0;
}