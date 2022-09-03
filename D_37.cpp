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

void level_order(treeNode *root, queue<int> &qu)
{
    if (root == NULL)
        return;
    queue<treeNode *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        treeNode *currNode = q.front();
        q.pop();
        if (currNode != NULL)
        {
            qu.push(root->data);
            if (currNode->leftChild != NULL)
            {
                q.push(currNode->leftChild);
            }

            if (currNode->rightChild != NULL)
            {
                q.push(currNode->rightChild);
            }
        }
        else
        {
            if (!q.empty())
                q.push(NULL);
        }
    }
}

int second_minimum(treeNode *root)
{
    static int minNum = root->data;
    static int secondMinNum = -1;
    if (root == NULL)
        return secondMinNum;
    if (minNum > root->data)
        minNum = root->data;
    if (minNum < root->data)
    {
        if (secondMinNum == -1)
            secondMinNum = root->data;
        else if (secondMinNum > root->data && minNum != root->data)
            secondMinNum = root->data;
    }
    second_minimum(root->leftChild);
    second_minimum(root->rightChild);
    return secondMinNum;
}

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

    cout << "Min is: " << second_minimum(root) << endl;
    printTree(root, 0);

    return 0;
}
