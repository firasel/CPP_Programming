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
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    int size = nums.size();
    unordered_map<int, int> mp;
    vector<pair<int, int>> track;
    vector<int> ans;
    for (int i = 0; i < size; i++)
      mp[nums[i]]++;
    for (auto mpEl : mp)
      track.push_back(make_pair(mpEl.second, mpEl.first));
    sort(track.rbegin(), track.rend());
    for (auto mpEl : track)
    {
      ans.push_back(mpEl.second);
      if (--k <= 0)
        return ans;
    }
    return ans;
  }
};

int main()
{
  Solution st;

  vector<int> nums1 = {1, 1, 1, 2, 2, 3};
  vector<int> nums2 = {3, 4};
  vector<int> res = st.topKFrequent(nums1, 2);
  for (auto num : res)
    cout << num << " ";
  cout << endl;
  return 0;
}