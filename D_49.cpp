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
  int removeElement(vector<int> &nums, int val)
  {
    for (auto it = nums.begin(); it != nums.end(); ++it)
      if (*it == val)
        nums.erase(it--);
    return nums.size();
  }
};

int main()
{
  Solution st;

  vector<int> nums1 = {0, 1, 2, 2, 3, 0, 4, 2};
  int res = st.removeElement(nums1, 2);
  cout << res << endl;
  for (auto num : nums1)
    cout << num << " ";
  cout << endl;
  return 0;
}