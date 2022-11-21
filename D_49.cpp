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
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
  {
    vector<int> track(n, 0);
    vector<int> ans;
    int size = edges.size();
    for (int i = 0; i < size; i++)
      track[edges[i][1]] += 1;
    for (int i = 0; i < n; i++)
      if (track[i] == 0)
        ans.push_back(i);
    return ans;
  }
};

int main()
{
  Solution st;

  vector<vector<int>> nums1 = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
  vector<int> res = st.findSmallestSetOfVertices(6, nums1);
  for (auto num : res)
    cout << num << endl;
  return 0;
}