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
  int lengthOfLIS(vector<int> &nums)
  {
    int size = nums.size(), ans = 1;
    vector<int> track(size, 1);
    for (int i = 0; i < size; i++)
    {
      for (int j = i - 1; j >= 0; j--)
      {
        if (nums[j] < nums[i])
        {
          track[i] = max(track[i], track[j] + 1);
          ans = max(ans, track[i]);
        }
      }
    }
    return ans;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  int res = st.lengthOfLIS(nums);
  cout << res << endl;
  return 0;
}