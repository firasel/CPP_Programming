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
  TreeNode *inOrderSuccessor(TreeNode *root)
  {
    TreeNode *curr = root;
    while (curr->left != NULL)
      curr = curr->left;
    return curr;
  }

  TreeNode *deleteNode(TreeNode *root, int key)
  {
    if (root == NULL)
      return root;
    if (root->val > key)
      root->left = deleteNode(root->left, key);
    else if (root->val < key)
      root->right = deleteNode(root->right, key);
    else if (root->val == key)
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
};

int main()
{
  Solution st;
  TreeNode *root = new TreeNode(1);
  TreeNode *n2 = new TreeNode(2);
  TreeNode *n3 = new TreeNode(3);
  TreeNode *n4 = new TreeNode(5);
  TreeNode *n5 = new TreeNode(4);

  root->left = n2;
  root->right = n3;
  n2->right = n4;
  n3->right = n5;

  TreeNode *res = st.deleteNode(root, 3);

  printTree(res);
  cout << endl;
  return 0;
}