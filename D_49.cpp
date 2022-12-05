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
  vector<int> replaceElements(vector<int> &arr)
  {
    int size = arr.size(), maxNum = INT_MIN, temp = arr[size - 1];
    for (int i = size - 1; i > 0; i--)
    {
      maxNum = max(maxNum, temp);
      temp = arr[i - 1];
      arr[i - 1] = maxNum;
    }
    arr[size - 1] = -1;
    return arr;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {17, 18, 5, 4, 6, 1};
  vector<int> res = st.replaceElements(nums);
  for (auto num : res)
    cout << num << " ";
  cout << endl;
  return 0;
}