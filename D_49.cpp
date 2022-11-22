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
  bool checkIfExist(vector<int> &arr)
  {
    unordered_set<int> set;
    for (int num : arr)
    {
      if (set.count(2 * num) || !(num % 2) && set.count(num / 2))
        return true;
      set.insert(num);
    }
    return false;
  }
};

int main()
{
  Solution st;

  vector<int> nums1 = {10, 2, 5, 3};
  vector<int> nums2 = {3, 4};
  bool res = st.checkIfExist(nums1);
  cout << res << endl;
  return 0;
}