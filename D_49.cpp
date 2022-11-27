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
  vector<int> findClosestElements(vector<int> &arr, int k, int x)
  {
    int size = arr.size();
    priority_queue<pair<int, int>> res;
    vector<int> ans;
    for (int i = 0; i < size; i++)
    {
      if (res.size() < k)
      {
        res.push({abs(arr[i] - x), arr[i]});
      }
      else
      {
        int dif = abs(arr[i] - x);
        if (dif < res.top().first || (dif == res.top().first && arr[i] < res.top().second))
        {
          res.pop();
          res.push({abs(arr[i] - x), arr[i]});
        }
      }
    }
    while (!res.empty())
    {
      ans.push_back(res.top().second);
      res.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {1, 2, 3, 4, 5};
  vector<int> res = st.findClosestElements(nums, 4, 3);
  for (auto num : res)
    cout << num << endl;
  return 0;
}