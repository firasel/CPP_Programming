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
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
  {
    vector<vector<int>> ans;
    if (points.size() == 0)
      return ans;
    priority_queue<pair<int, pair<int, int>>> pq;
    int dis;
    for (auto point : points)
    {
      dis = point[0] * point[0] + point[1] * point[1];
      if (pq.size() < k)
        pq.push({dis, {point[0], point[1]}});
      else
      {
        if (dis < pq.top().first)
        {
          pq.pop();
          pq.push({dis, {point[0], point[1]}});
        }
      }
    }
    while (!pq.empty())
    {
      ans.push_back({pq.top().second.first, pq.top().second.second});
      pq.pop();
    }
    return ans;
  }
};

int main()
{
  Solution st;

  vector<vector<int>> nums = {{3, 3}, {5, -1}, {-2, 4}};
  vector<vector<int>> res = st.kClosest(nums, 2);
  for (auto nums : res)
  {
    for (auto num : nums)
      cout << num << " ";
    cout << endl;
  }
  return 0;
}