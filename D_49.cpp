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

void printTree(TreeNode *root, string &str)
{
  if (root == NULL)
  {
    str += "NULL_";
    return;
  }
  cout << root->val << " ";
  str += to_string(root->val) + '_';
  printTree(root->left, str);
  printTree(root->right, str);
};

class Solution
{
public:
  void printVector(vector<int> nums)
  {
    cout << "Vect: ";
    for (auto num : nums)
      cout
          << num << " ";
    cout << endl;
  }

  int searchVector(vector<int> &nums, int val)
  {
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == val)
        return i;
    }
    return -1;
  }

  void copyVector(vector<int> &nums, vector<int> &res, int st, int end)
  {
    res.clear();
    for (st; st < end; st++)
    {
      res.push_back(nums[st]);
    }
  }

  TreeNode *createBST(vector<int> &preorder, vector<int> &inorder)
  {
    if (inorder.size() == 0 || preorder.size() == 0)
      return NULL;
    int pos = searchVector(inorder, preorder[0]);
    if (pos == -1)
      return NULL;
    TreeNode *root = new TreeNode(preorder[0]);
    preorder.erase(preorder.begin());
    vector<int> temp;
    copyVector(inorder, temp, 0, pos);
    if (!temp.empty())
      root->left = createBST(preorder, temp);

    copyVector(inorder, temp, pos + 1, inorder.size());
    if (!temp.empty())
      root->right = createBST(preorder, temp);

    return root;
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    TreeNode *root;
    root = createBST(preorder, inorder);
    return root;
  }
};

int main()
{
  Solution st;
  vector<int> nums1 = {3, 9, 20, 15, 7};
  vector<int> nums2 = {9, 3, 15, 20, 7};
  TreeNode *res = st.buildTree(nums1, nums2);
  cout << endl;
  string treeStr = "";
  printTree(res, treeStr);
  cout << endl;
  cout << endl
       << treeStr << endl;
  return 0;
}