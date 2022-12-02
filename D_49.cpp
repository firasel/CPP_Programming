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
  bool closeStrings(string word1, string word2)
  {
    if (word1.length() != word2.length())
      return false;
    unordered_map<char, int> mp1, mp2;
    vector<int> num1, num2;
    for (char ch : word1)
      mp1[ch]++;
    for (char ch : word2)
      mp2[ch]++;

    if (mp1.size() != mp2.size())
      return false;

    for (auto mpEl : mp1)
    {
      if (mp2.find(mpEl.first) == mp2.end())
        return false;
      num1.push_back(mpEl.second);
    }
    for (auto mpEl : mp2)
      num2.push_back(mpEl.second);

    sort(num1.begin(), num1.end());
    sort(num2.begin(), num2.end());
    return num1 == num2;
  }
};

int main()
{
  Solution st;
  bool res = st.closeStrings("abc", "abd");
  cout << res << endl;
  return 0;
}