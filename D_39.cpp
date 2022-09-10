#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value)
    {
        val = value;
        left = NULL;
        right = NULL;
    }
};

void spacePrint(int level)
{
    for (int i = 0; i < level; i++)
        cout << "    ";
}

void printTree(TreeNode *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->val << endl;
        return;
    }
    else
    {
        cout << endl;
        spacePrint(level);
        cout << "Root: " << root->val << endl;
    }

    if (root->left != NULL)
    {
        spacePrint(level);
        cout << "Left: ";
        printTree(root->left, level + 1);
    }

    if (root->right != NULL)
    {
        spacePrint(level);
        cout << "Right: ";
        printTree(root->right, level + 1);
    }
}

void inOrder(TreeNode *root, string &str)
{
    if (root == NULL)
        return;
    inOrder(root->left, str);
    str += (to_string(root->val) + " ");
    inOrder(root->right, str);
}

TreeNode *insertionBST(TreeNode *root, int value)
{
    TreeNode *newNode = new TreeNode(value);

    if (root == NULL)
    {
        root = newNode;
        return root;
    }
    if (root->val > value)
    {
        root->left = insertionBST(root->left, value);
    }
    else if (root->val < value)
    {
        root->right = insertionBST(root->right, value);
    }

    return root;
}

int main()
{
    int n;
    cin >> n;
    TreeNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        root = insertionBST(root, value);
    }

    string inOrderStr;
    inOrder(root, inOrderStr);
    cout << inOrderStr << endl;

    return 0;
}
