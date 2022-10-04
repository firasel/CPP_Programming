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
  bool findNodePath(TreeNode *root, int val, string &path)
  {
    if (!root)
      return false;
    if (root->val == val)
      return true;
    path += 'L';
    auto result = findNodePath(root->left, val, path);
    if (result)
      return true;
    path.pop_back();
    path += 'R';
    result = findNodePath(root->right, val, path);
    if (result)
      return true;
    path.pop_back();
    return false;
  }

  TreeNode *LCAFind(TreeNode *root, int x, int y)
  {
    if (!root)
      return NULL;
    if (root->val == x)
      return root;
    if (root->val == y)
      return root;
    TreeNode *root1 = LCAFind(root->left, x, y);
    TreeNode *root2 = LCAFind(root->right, x, y);
    if (root1 && root2)
      return root;
    return root1 ? root1 : root2;
  }

  string getDirections(TreeNode *root, int startValue, int destValue)
  {
    root = LCAFind(root, startValue, destValue);
    string startPath = "", endPath = "";
    findNodePath(root, startValue, startPath);
    findNodePath(root, destValue, endPath);
    for (auto &str : startPath)
      str = 'U';
    return startPath + endPath;
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
  TreeNode *mainRoot = new TreeNode(5);
  TreeNode *root1 = new TreeNode(1);
  TreeNode *root2 = new TreeNode(2);
  TreeNode *root3 = new TreeNode(3);
  TreeNode *root4 = new TreeNode(6);
  TreeNode *root5 = new TreeNode(4);
  // TreeNode *root6 = new TreeNode(7);
  // TreeNode *root7 = new TreeNode(3);
  // TreeNode *root8 = new TreeNode(8);

  mainRoot->left = root1;
  mainRoot->right = root2;
  root1->left = root3;
  root2->left = root4;
  root2->right = root5;
  // root1->right = root4;
  // root4->right = root7;
  // root2->left = root5;
  // root2->right = root6;
  // root6->right = root8;

  preOrder(mainRoot);
  cout << endl;
  cout << st.getDirections(mainRoot, 3, 6) << endl;
  return 0;
}