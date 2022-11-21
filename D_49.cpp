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
  int removeDuplicates(vector<int> &nums)
  {
    int k = 0, i, size = nums.size();
    for (i = 0; i < size; i++)
      if (nums[k] != nums[i])
        nums[++k] = nums[i];
    return k + 1;
  }
};

int main()
{
  Solution st;

  vector<int> nums1 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int res = st.removeDuplicates(nums1);
  cout << res << endl;
  for (auto num : nums1)
    cout << num << " ";
  cout << endl;
  return 0;
}