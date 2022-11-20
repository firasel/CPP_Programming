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
};

class Codec
{
public:
  string ans = "";
  int strToNum(string &data)
  {
    string temp = "";
    int i, num;
    for (i = 0; i < data.length(); i++)
    {
      if (data[i] == '(')
        break;
      temp += data[i];
    }
    data = data.substr(i);
    num = stoi(temp);
    return num;
  }

  string splitStr(string &data)
  {
    string temp = "";
    int i, cnt = 0;
    for (i = 0; i < data.length(); i++)
    {
      if (data[i] == '(')
        cnt++;
      else if (data[i] == ')')
        cnt--;
      if (cnt == 0)
      {
        temp = data.substr(1, i - 1);
        break;
      }
    }
    data = data.substr(i + 1);
    return temp;
  }

  // Encodes a tree to a single string.
  string serialize(TreeNode *root)
  {
    if (root == NULL)
      return ans;
    ans += to_string(root->val);
    if (root->left)
    {
      ans += '(';
      serialize(root->left);
      ans += ')';
    }
    else if (root->right)
      ans += "()";
    if (root->right)
    {
      ans += '(';
      serialize(root->right);
      ans += ')';
    }
    return ans;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data)
  {
    if (data == "")
      return NULL;
    string temp = "", left = "", right = "";
    TreeNode *root = new TreeNode(strToNum(data));
    if (data != "")
      left = splitStr(data);
    if (data != "")
      right = splitStr(data);
    root->left = deserialize(left);
    root->right = deserialize(right);
    return root;
  }
};

int main()
{
  Solution st;
  Codec ser, deser;
  TreeNode *root = new TreeNode(1);
  TreeNode *n2 = new TreeNode(2);
  TreeNode *n3 = new TreeNode(3);
  TreeNode *n4 = new TreeNode(4);
  TreeNode *n5 = new TreeNode(5);
  TreeNode *n6 = new TreeNode(6);
  TreeNode *n7 = new TreeNode(7);
  TreeNode *n8 = new TreeNode(8);
  root->left = n2;
  root->right = n3;
  n2->left = n6;
  n2->right = n7;
  n3->left = n4;
  n3->right = n5;
  n4->right = n8;
  TreeNode *res = deser.deserialize(ser.serialize(root));
  cout << endl
       << "Tree: " << endl;
  printTree(res);
  cout << endl
       << endl;
  return 0;
}