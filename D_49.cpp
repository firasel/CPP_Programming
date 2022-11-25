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
    int ans = INT32_MAX, size = nums.size(), sum = 0, left = 0, right = 0;
    while (right < size)
    {
      sum += nums[right];
      while (sum >= target)
      {
        ans = min(right - left + 1, ans);
        sum -= nums[left];
        left++;
      }
      right++;
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