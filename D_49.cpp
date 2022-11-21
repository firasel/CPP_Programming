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
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    sort(nums1.begin(), nums1.end());
    int size = nums1.size();
    cout << fixed << setprecision(5);
    if (size % 2 == 0)
      return ((double)nums1[(size / 2) - 1] + (double)nums1[size / 2]) / 2;
    return (double)nums1[size / 2];
  }
};

int main()
{
  Solution st;

  vector<int> nums1 = {1, 2};
  vector<int> nums2 = {3, 4};
  double res = st.findMedianSortedArrays(nums1, nums2);
  cout << res << endl;
  return 0;
}