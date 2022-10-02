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
  void insertNode(TreeNode *&root, int pos, int value, bool left)
  {
    if (root == NULL && pos == 0)
    {
      root = new TreeNode(value);
      return;
    }
    if (root)
      cout << root->val << " " << left << " ";
    if (!root->left && pos == 1)
    {
      root->left = new TreeNode(value);
      return;
    }
    if (!root->right && pos == 1)
    {
      root->right = new TreeNode(value);
      return;
    }
    if (root->left && left)
      insertNode(root->left, pos - 1, value, left);
    if (root->right && !left)
      insertNode(root->right, pos - 1, value, left);
  }

  TreeNode *recoverFromPreorder(string traversal)
  {
    if (traversal == "" || traversal[0] == '-')
      return NULL;
    string numStr = "";
    for (int i = 0; i < traversal.length(); i++)
    {
      if (traversal[i] != '-')
        numStr += traversal[i];
      else
        break;
    }
    int num = stoi(numStr);

    TreeNode *root = new TreeNode(num);
    int s = 0, e = 0;
    string curr, next;

    for (int i = 0; i < traversal.length(); i++)
    {
      if (traversal[i] == '-')
      {
        s = i;
        curr += traversal[i];
      }
      if (s != 0 && traversal[i] != '-')
      {
        s = i;
        break;
      }
    }

    for (int i = s; i < traversal.length(); i++)
    {
      if (traversal[i] == '-')
      {
        e = i;
        next += traversal[i];
      }
      if (traversal[i] != '-')
      {
        if (e != 0 && curr == next)
        {
          e = i;
          break;
        }
        else
        {
          next = "";
          e = 0;
        }
      }
    }

    int st = s, ed = e - s - next.length();
    string s1 = s == e ? "" : traversal.substr(st, ed);

    st = e;
    string s2 = s == e ? "" : traversal.substr(st);

    if (traversal != s1)
      root->left = recoverFromPreorder(s1);
    if (traversal != s2)
      root->right = recoverFromPreorder(s2);
    return root;
  }
};

void inOrder(TreeNode *root)
{
  if (root == NULL)
    return;
  cout << root->val << " ";
  inOrder(root->left);
  inOrder(root->right);
}

int main()
{
  Solution st;
  TreeNode *root = st.recoverFromPreorder("1-401--349---90--88");
  inOrder(root);
  return 0;
}