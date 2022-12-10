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
  printTree(root->left);
  cout << root->val << " ";
  printTree(root->right);
};

class Solution
{
public:
  int maximumValue(vector<string> &strs)
  {
    int n = strs.size(), len, max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
      len = 0;
      for (auto ch : strs[i])
      {
        if (ch >= 'a' && ch <= 'z')
        {
          len = strs[i].length();
          break;
        }
      }
      if (!len)
        len = stoi(strs[i]);
      cout << strs[i] << " " << len << endl;
      if (max < len)
        max = len;
    }
    return max;
  }
};

int main()
{
  Solution st;
  vector<string> strs = {"1", "01", "001", "0100"};
  int res = st.maximumValue(strs);
  cout << res << endl;
  return 0;
}