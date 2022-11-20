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
  void duplicateZeros(vector<int> &arr)
  {
    queue<int> nums;
    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i] == 0)
        nums.push(arr[i]);
      if (!nums.empty())
      {
        nums.push(arr[i]);
        arr[i] = nums.front();
        nums.pop();
      }
    }
  }
};

int main()
{
  Solution st;

  vector<int> nums = {1, 0, 2, 3, 0, 4, 5, 0};
  st.duplicateZeros(nums);
  for (auto num : nums)
    cout << num << " ";
  cout << endl;
  return 0;
}