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
  long long dividePlayers(vector<int> &skill)
  {
    int size = skill.size();
    long long temp = INT_MIN, sum = 0;
    sort(skill.begin(), skill.end());
    for (int i = 0; i < size / 2; i++)
    {
      if (temp != INT_MIN && temp != skill[i] + skill[size - 1 - i])
        return -1;
      temp = skill[i] + skill[size - 1 - i];
      sum += (skill[i] * skill[size - 1 - i]);
    }
    return sum;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {1, 1, 2, 3};
  long long res = st.dividePlayers(nums);
  cout << res << endl;
  return 0;
}