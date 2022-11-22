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
  bool validMountainArray(vector<int> &arr)
  {
    int size = arr.size() - 1, flag = 0, i = 0;
    if (size < 2)
      return false;
    for (i = 0; i < size - 1; i++)
    {
      if (arr[i] == arr[i + 1])
        return false;
      if (arr[i] > arr[i + 1])
        break;
    }
    if (i == 0)
      return false;
    for (i; i < size; i++)
      if (arr[i] == arr[i + 1] || arr[i] < arr[i + 1])
        return false;
    return true;
  }
};

int main()
{
  Solution st;

  vector<int> nums1 = {0, 3, 2, 1};
  vector<int> nums2 = {3, 4};
  bool res = st.validMountainArray(nums1);
  cout << res << endl;
  return 0;
}