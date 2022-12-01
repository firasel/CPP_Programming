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
  bool isVowel(char &ch)
  {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
      return true;
    return false;
  }
  bool halvesAreAlike(string s)
  {
    int size = s.length(), a = 0, b = 0, i;
    for (i = 0; i < size / 2; i++)
      if (isVowel(s[i]))
        a++;
    for (; i < size; i++)
      if (isVowel(s[i]))
        b++;
    return a == b;
  }
};

int main()
{
  Solution st;
  bool res = st.halvesAreAlike("book");
  cout << res << endl;
  return 0;
}