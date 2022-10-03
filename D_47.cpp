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
  TreeNode *inOrderSuccessor(TreeNode *root)
  {
    TreeNode *curr = root;
    while (curr->left != NULL)
    {
      curr = curr->left;
    }
    return curr;
  }

  TreeNode *deleteNode(TreeNode *root, int key)
  {
    if (root == NULL)
      return root;
    if (root->val == key)
    {
      if (!root->left && !root->right)
      {
        delete root;
        return NULL;
      }
      else if (root->left == NULL)
      {
        TreeNode *temp = root->right;
        delete root;
        return temp;
      }
      else if (root->right == NULL)
      {
        TreeNode *temp = root->left;
        delete root;
        return temp;
      }
      else
      {
        TreeNode *temp = inOrderSuccessor(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
      }
    }
    return root;
  }

  TreeNode *trimBST(TreeNode *root, int low, int high)
  {
    if (root == NULL)
      return root;
    if (root->val >= low && root->val <= high)
    {
      root->left = trimBST(root->left, low, high);
      root->right = trimBST(root->right, low, high);
    }
    else
    {
      root = deleteNode(root, root->val);
      trimBST(root, low, high);
    }

    return root;
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
  TreeNode *mainRoot = new TreeNode(2);
  TreeNode *root1 = new TreeNode(1);
  TreeNode *root2 = new TreeNode(3);
  // TreeNode *root3 = new TreeNode(1);
  // TreeNode *root4 = new TreeNode(4);

  mainRoot->left = root1;
  mainRoot->right = root2;
  // root1->right = root2;
  // root2->left = root3;
  // mainRoot->right = root4;

  preOrder(mainRoot);
  cout << endl;
  TreeNode *root = st.trimBST(mainRoot, 3, 4);
  preOrder(root);
  return 0;
}