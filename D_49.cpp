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
  string frequencySort(string s)
  {
    unordered_map<char, string> mp;
    vector<pair<int, char>> charVect;
    for (char ch : s)
      mp[ch] += ch;
    for (auto mpEl : mp)
      charVect.push_back(make_pair(mpEl.second.length(), mpEl.first));
    sort(charVect.rbegin(), charVect.rend());
    s = "";
    for (auto vectEl : charVect)
      s += mp[vectEl.second];
    return s;
  }
};

int main()
{
  Solution st;

  vector<int> nums1 = {0, 3, 2, 1};
  vector<int> nums2 = {3, 4};
  string res = st.frequencySort("aacccaa");
  cout << res << endl;
  return 0;
}