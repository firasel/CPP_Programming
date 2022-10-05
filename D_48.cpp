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
  void preOrder(TreeNode *root, vector<TreeNode *> &lists)
  {
    if (root == NULL)
      return;
    lists.push_back(root);
    preOrder(root->left, lists);
    preOrder(root->right, lists);
  }
  void flatten(TreeNode *root)
  {
    if (root == NULL)
      return;
    vector<TreeNode *> lists;
    preOrder(root, lists);
    int size = lists.size();
    for (int i = 0; i < size - 1; i++)
    {
      lists[i]->left = NULL;
      lists[i]->right = lists[i + 1];
    }
  }
};

void printList(TreeNode *head)
{
  if (head == NULL)
    return;
  cout << head->val << " ";
  printList(head->right);
}

int main()
{
  TreeNode *root = new TreeNode(1);
  TreeNode *node1 = new TreeNode(2);
  TreeNode *node2 = new TreeNode(3);
  TreeNode *node3 = new TreeNode(4);
  TreeNode *node4 = new TreeNode(5);
  TreeNode *node5 = new TreeNode(6);
  root->left = node1;
  node1->left = node2;
  node1->right = node3;
  root->right = node4;
  node4->right = node5;

  Solution st;
  st.flatten(root);
  printList(root);
  cout << endl;
  return 0;
};
