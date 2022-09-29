#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        next = NULL;
    }
};

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

class BSTIterator
{
public:
    queue<int> allNodes;
    BSTIterator(TreeNode *root)
    {
        while (!allNodes.empty())
            allNodes.pop();
        preOrder(root);
    }
    void preOrder(TreeNode *root)
    {
        if (root == NULL)
            return;
        preOrder(root->left);
        allNodes.push(root->val);
        preOrder(root->right);
    }

    int next()
    {
        if (allNodes.empty())
            return NULL;
        int num = allNodes.front();
        allNodes.pop();
        return num;
    }

    bool hasNext()
    {
        return !allNodes.empty();
    }
};

int main()
{
    return 0;
}
