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
  int findKthLargest(vector<int> &nums, int k)
  {
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
  }
};

int main()
{
  Solution st;

  vector<int> nums1 = {3, 2, 1, 5, 6, 4};
  vector<int> nums2 = {3, 4};
  int res = st.findKthLargest(nums1, 2);
  cout << res << endl;
  return 0;
}