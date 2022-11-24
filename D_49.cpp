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
  int minSubArrayLen(int target, vector<int> &nums)
  {
    int ans = INT32_MAX, size = nums.size();
    for (int i = 1; i < size; i++)
      nums[i] = nums[i - 1] + nums[i];
    if (nums.back() < target)
      return 0;
    else if (nums.back() == target)
      return size;
    for (int i = size - 1; i >= 0; i--)
    {
      if (nums[i] >= target && ans > i + 1)
        ans = i + 1;
      for (int j = 0; j < i; j++)
      {
        if (nums[i] - nums[j] >= target && ans > i - j)
          ans = i - j;
        else if (nums[i] - nums[j] < target)
          break;
      }
    }
    return ans == INT32_MAX ? 0 : ans;
  }
};

int main()
{
  Solution st;

  vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
  int res = st.minSubArrayLen(11, nums);
  cout << res << endl;
  return 0;
}