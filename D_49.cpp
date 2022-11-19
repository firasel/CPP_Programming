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
  int findMaxConsecutiveOnes(vector<int> &nums)
  {
    int ans = 0, cnt = 0, size = nums.size();
    for (int i = 0; i < size; i++)
    {
      if (nums[i] == 0)
      {
        ans = ans < cnt ? cnt : ans;
        cnt = 0;
      }
      else
        cnt++;
    }
    ans = ans < cnt ? cnt : ans;
    return ans;
  }
};

int main()
{
  Solution st;
  // TreeNode *root = new TreeNode(3);
  // TreeNode *n2 = new TreeNode(1);
  // TreeNode *n3 = new TreeNode(4);
  // TreeNode *n4 = new TreeNode(2);

  // root->left = n2;
  // root->right = n3;
  // n2->right = n4;
  vector<int> nums = {1, 1, 0, 1, 1, 1};
  int res = st.findMaxConsecutiveOnes(nums);

  cout << res << endl;
  return 0;
}