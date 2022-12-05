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
    int i = 0, size = nums.size(), j = size - 1, tmp;
    while (i < size)
    {
      if (nums[i] % 2 != 0)
      {
        while (j >= 0 && nums[j] % 2 != 0)
          j--;
        if (i >= j)
          break;
        tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        j--;
      }
      i++;
    }
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