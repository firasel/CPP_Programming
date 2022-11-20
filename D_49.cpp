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
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    n--;
    while (n >= 0)
      nums1[m++] = nums2[n--];
    sort(nums1.begin(), nums1.end());
  }
};

int main()
{
  Solution st;

  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};
  st.merge(nums1, 3, nums2, 3);
  for (auto num : nums1)
    cout << num << " ";
  cout << endl;
  return 0;
}