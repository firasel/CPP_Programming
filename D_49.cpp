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
  void removeDupWord(string &str, vector<string> &words)
  {
    string word = "";
    for (auto x : str)
    {
      if (x == ' ')
      {
        if (word != "")
          words.push_back(word);
        word = "";
      }
      else
        word = word + x;
    }
    if (word != "")
      words.push_back(word);
  }

  bool isCircularSentence(string sentence)
  {
    vector<string> words;
    removeDupWord(sentence, words);
    int size = words.size();
    if (size > 1)
    {
      for (int i = 0; i < size - 1; i++)
      {
        if (words[i].back() != words[i + 1].front())
          return false;
      }
    }
    return words[0].front() == words[size - 1].back();
  }
};

int main()
{
  Solution st;
  bool res = st.isCircularSentence("leetcode exercises sound delightful");
  cout << res << endl;
  return 0;
}