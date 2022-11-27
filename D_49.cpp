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
  int triangleNumber(vector<int> &nums)
  {
    int size = nums.size(), ans = 0, l, h;
    sort(nums.begin(), nums.end());
    for (int i = size - 1; i >= 2; i--)
    {
      l = 0;
      h = i - 1;
      while (l < h)
      {
        if (nums[l] + nums[h] > nums[i])
        {
          ans += (h - l);
          h--;
        }
        else
          l++;
      }
    }
    return ans;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {2, 2, 3, 4};
  int res = st.triangleNumber(nums);
  cout << res << endl;
  return 0;
}