#include <bits/stdc++.h>
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

class Solution
{
public:
  vector<int> nums;

  void inOrder(TreeNode *root)
  {
    if (root == NULL)
      return;
    inOrder(root->left);
    nums.push_back(root->val);
    inOrder(root->right);
  }

  TreeNode *makeBalanceBST(TreeNode *root, int start, int end)
  {
    if (start > end)
      return root;
    int mid = (start + end) / 2;
    TreeNode *newNode = new TreeNode(nums[mid]);
    root = newNode;
    root->left = makeBalanceBST(root->left, start, mid - 1);
    root->right = makeBalanceBST(root->right, mid + 1, end);
    return root;
  }

  TreeNode *balanceBST(TreeNode *root)
  {
    TreeNode *newRoot = NULL;
    if (root == NULL)
      return newRoot;
    nums.clear();
    inOrder(root);
    newRoot = makeBalanceBST(newRoot, 0, nums.size() - 1);
    return newRoot;
  }
};

void preOrder(TreeNode *root)
{
  if (root == NULL)
    return;
  cout << root->val << " ";
  preOrder(root->left);
  preOrder(root->right);
}

int main()
{
  Solution st;
  TreeNode *mainRoot = new TreeNode(1);
  TreeNode *root1 = new TreeNode(2);
  TreeNode *root2 = new TreeNode(3);
  TreeNode *root3 = new TreeNode(4);
  // TreeNode *root4 = new TreeNode(2);
  // TreeNode *root5 = new TreeNode(5);
  // TreeNode *root6 = new TreeNode(7);
  // TreeNode *root7 = new TreeNode(3);
  // TreeNode *root8 = new TreeNode(8);

  mainRoot->right = root1;
  root1->right = root2;
  root2->right = root3;
  // root1->right = root4;
  // root4->right = root7;
  // root2->left = root5;
  // root2->right = root6;
  // root6->right = root8;

  preOrder(mainRoot);
  cout << endl;
  TreeNode *root = st.balanceBST(mainRoot);
  cout << endl;
  preOrder(root);
  return 0;
}