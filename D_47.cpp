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
  int mostWordsFound(vector<string> &sentences)
  {
    int max = 0;
    for (auto str : sentences)
    {
      int count = 0;
      for (auto ch : str)
        if (ch == ' ')
          count++;
      if (str != "" && str != " ")
        count++;
      if (max < count)
        max = count;
    }
    return max;
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
  // TreeNode *mainRoot = new TreeNode(2);
  // TreeNode *root1 = new TreeNode(1);
  // TreeNode *root2 = new TreeNode(3);
  // TreeNode *root3 = new TreeNode(0);
  // TreeNode *root4 = new TreeNode(1);
  // TreeNode *root5 = new TreeNode(4);
  // TreeNode *root6 = new TreeNode(7);
  // TreeNode *root7 = new TreeNode(3);
  // TreeNode *root8 = new TreeNode(8);

  // mainRoot->left = root1;
  // mainRoot->right = root2;
  // root2->left = root3;
  // root2->right = root4;
  // root1->right = root4;
  // root4->right = root7;
  // root2->left = root5;
  // root2->right = root6;
  // root6->right = root8;

  // preOrder(mainRoot);
  // cout << endl;
  vector<string> sentences = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
  vector<string> sentences2 = {"please wait", "continue to fight", "continue to win"};
  cout << st.mostWordsFound(sentences) << endl;
  cout << st.mostWordsFound(sentences2) << endl;
  return 0;
}