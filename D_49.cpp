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
  int findNumbers(vector<int> &nums)
  {
    int cnt = 0;
    for (auto num : nums)
      if (to_string(num).length() % 2 == 0)
        cnt++;
    return cnt;
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
  vector<int> nums = {12, 345, 2, 6, 7896};
  int res = st.findNumbers(nums);

  cout << res << endl;
  return 0;
}