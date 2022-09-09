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

void spacePrint(int level);
void printTree(TreeNode *root, int level);

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

void insertNodeAtTree(TreeNode *root, int key, int leftValue, int rightValue)
{
    if (root == NULL)
    {
        return;
    }
    static bool chkl = true;
    static bool chkr = true;
    if (root->val == key && root->left == NULL && leftValue != -1)
    {
        TreeNode *newNode = new TreeNode(leftValue);
        root->left = newNode;
        leftValue = -1;
        chkl = false;
    }
    if (root->val == key && root->right == NULL && rightValue != -1)
    {
        TreeNode *newNode = new TreeNode(rightValue);
        root->right = newNode;
        rightValue = -1;
        chkr = false;
    }
    insertNodeAtTree(root->left, key, leftValue, rightValue);
    if (chkl || chkr)
    {
        cout << chkl << " " << chkr << " " << key << " " << leftValue << " " << rightValue << endl;
        insertNodeAtTree(root->right, key, leftValue, rightValue);
    }
}

class Solution
{
public:
    void treePathMake(TreeNode *root, string path, vector<string> *strVect)
    {
        path += to_string(root->val);
        if (!root->left && !root->right)
        {
            strVect->push_back(path);
            return;
        }
        if (root->left)
        {
            path += "->";
            treePathMake(root->left, path, strVect);
        }
        if (root->right)
        {
            if (!root->left)
                path += "->";
            treePathMake(root->right, path, strVect);
        }
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ansVect;
        treePathMake(root, "", &ansVect);
        return ansVect;
    }
};

int main()
{
    int a;
    cin >> a;
    TreeNode *root = new TreeNode(a);
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *presentRoot = q.front();
        q.pop();
        int x, y;
        cin >> x >> y;
        TreeNode *n1 = NULL;
        TreeNode *n2 = NULL;
        if (x != -1)
            n1 = new TreeNode(x);
        if (y != -1)
            n2 = new TreeNode(y);
        presentRoot->left = n1;
        presentRoot->right = n2;
        if (n1 != NULL)
            q.push(n1);
        if (n2 != NULL)
            q.push(n2);
    }

    Solution st;
    vector<string> result = st.binaryTreePaths(root);

    for (string str : result)
    {
        cout << str << endl;
    }

    // TreeNode *root2 = st.pruneTree(root);
    printTree(root, 0);
    // printTree(root2, 0);

    return 0;
}
