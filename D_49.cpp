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
    int size = arr.size(), max;
    vector<pair<int, int>> hp;
    for (int i = 0; i < size; i++)
    {
      if (hp.empty())
        hp.push_back({arr[i], i});
      else if (hp.back().first > arr[i])
        hp.push_back({arr[i], i});
      else
      {
        while (!hp.empty() && hp.back().first < arr[i])
          hp.pop_back();
        hp.push_back({arr[i], i});
      }
    }
    reverse(hp.begin(), hp.end());
    for (int i = 0; i < size - 1; i++)
    {
      if (hp.back().second <= i)
        hp.pop_back();
      arr[i] = hp.back().first;
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