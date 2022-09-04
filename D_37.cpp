#include <bits/stdc++.h>
using namespace std;

class treeNode
{
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;
    treeNode(int val)
    {
        data = val;
        leftChild = NULL;
        rightChild = NULL;
    }
};

void spacePrint(int level);
void printTree(treeNode *root, int level);

void spacePrint(int level)
{
    for (int i = 0; i < level; i++)
        cout << "    ";
}

void printTree(treeNode *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        cout << root->data << endl;
        return;
    }
    else
    {
        cout << endl;
        spacePrint(level);
        cout << "Root: " << root->data << endl;
    }

    if (root->leftChild != NULL)
    {
        spacePrint(level);
        cout << "Left: ";
        printTree(root->leftChild, level + 1);
    }

    if (root->rightChild != NULL)
    {
        spacePrint(level);
        cout << "Right: ";
        printTree(root->rightChild, level + 1);
    }
}

void insertNodeAtTree(treeNode *root, int key, int leftValue, int rightValue)
{
    if (root == NULL)
    {
        return;
    }
    static bool chkl = true;
    static bool chkr = true;
    if (root->data == key && root->leftChild == NULL && leftValue != -1)
    {
        treeNode *newNode = new treeNode(leftValue);
        root->leftChild = newNode;
        leftValue = -1;
        chkl = false;
    }
    if (root->data == key && root->rightChild == NULL && rightValue != -1)
    {
        treeNode *newNode = new treeNode(rightValue);
        root->rightChild = newNode;
        rightValue = -1;
        chkr = false;
    }
    insertNodeAtTree(root->leftChild, key, leftValue, rightValue);
    if (chkl || chkr)
    {
        cout << chkl << " " << chkr << " " << key << " " << leftValue << " " << rightValue << endl;
        insertNodeAtTree(root->rightChild, key, leftValue, rightValue);
    }
}

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> temp;
    int minCol = INT_MAX;
    void verticalTree(treeNode *root, int col)
    {
        if (minCol > col)
            minCol = col;
        if (root->leftChild != NULL)
            verticalTree(root->leftChild, col - 1);

        if (res.size() > col + abs(minCol))
        {

            res[col + abs(minCol)].push_back(root->data);
        }
        else
        {
            temp.push_back(root->data);
            res.push_back(temp);
            temp.clear();
        }

        if (root->rightChild != NULL)
            verticalTree(root->rightChild, col + 1);
    }

    vector<vector<int>> verticalTraversal(treeNode *root)
    {
        if (root == NULL)
            return res;
        res.clear();
        verticalTree(root, 0);
        for (int i = 0; i < res.size(); i++)
            if (res[i].size() > 1)
                sort(res[i].begin(), res[i].end());
        return res;
    }
};

int main()
{
    int a;
    cin >> a;
    treeNode *root = new treeNode(a);
    queue<treeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        treeNode *presentRoot = q.front();
        q.pop();
        int x, y;
        cin >> x >> y;
        treeNode *n1 = NULL;
        treeNode *n2 = NULL;
        if (x != -1)
            n1 = new treeNode(x);
        if (y != -1)
            n2 = new treeNode(y);
        presentRoot->leftChild = n1;
        presentRoot->rightChild = n2;
        if (n1 != NULL)
            q.push(n1);
        if (n2 != NULL)
            q.push(n2);
    }

    Solution st;
    vector<vector<int>> vt = st.verticalTraversal(root);
    for (int i = 0; i < vt.size(); i++)
    {
        for (int j = 0; j < vt[i].size(); j++)
            cout << vt[i][j] << " ";
        cout << endl;
    }
    printTree(root, 0);

    return 0;
}
