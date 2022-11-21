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
  int findJudge(int n, vector<vector<int>> &trust)
  {
    vector<int> track(n + 1, 0);
    int size = trust.size();
    for (int i = 0; i < size; i++)
      track[trust[i][0]]--, track[trust[i][1]]++;
    for (int i = 1; i <= n; i++)
      if (track[i] == n - 1)
        return i;
    return -1;
  }
};

int main()
{
  Solution st;

  vector<vector<int>> nums1 = {{1, 3}, {2, 3}};
  int res = st.findJudge(3, nums1);
  cout << res << endl;
  return 0;
}