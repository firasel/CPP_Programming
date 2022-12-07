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
  printTree(root->left);
  cout << root->val << " ";
  printTree(root->right);
};

class Solution
{
public:
  int thirdMax(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    int i = nums.size() - 1, max1, max2;
    max1 = nums[i];
    while (--i >= 0)
      if (nums[i] != max1)
      {
        max2 = nums[i];
        break;
      }

    while (--i >= 0)
      if (nums[i] != max1 && nums[i] != max2)
        return nums[i];

    return max1;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {2, 2, 1, 3, 4, 5, 6};
  int res = st.thirdMax(nums);
  cout << res << endl;
  return 0;
}