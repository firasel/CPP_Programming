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
  bool isValidTriangle(int &a, int &b, int &c)
  {
    if (a + b > c && a + c > b && b + c > a)
      return true;
    return false;
  }
  int triangleNumber(vector<int> &nums)
  {
    int size = nums.size(), cnt = 0;
    if (size < 3)
      return cnt;
    size -= 2;
    for (int i = 0; i < size; i++)
    {
      if (isValidTriangle(nums[i], nums[i + 1], nums[i + 2]))
        cnt++;
    }
    do
    {
      for (auto num : nums)
        cout << num << " ";
      cout << endl;
    } while (next_permutation(nums.begin(), nums.end()));

    return cnt;
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