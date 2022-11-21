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
  void visitRoom(vector<vector<int>> &rooms, map<int, bool> &mp, int key)
  {
    if (mp.find(key) == mp.end())
    {
      mp[key] = true;
      for (auto num : rooms[key])
        if (mp.find(num) == mp.end())
          visitRoom(rooms, mp, num);
    }
  }
  bool canVisitAllRooms(vector<vector<int>> &rooms)
  {
    map<int, bool> mp;
    visitRoom(rooms, mp, 0);
    if (mp.size() == rooms.size())
      return true;
    return false;
  }
};

int main()
{
  Solution st;

  vector<vector<int>> nums1 = {{1, 3}, {3, 0, 1}, {2}, {0}};
  bool res = st.canVisitAllRooms(nums1);
  cout << res << endl;
  return 0;
}