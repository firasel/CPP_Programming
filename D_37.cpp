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
    if (root->data == key && root->leftChild == NULL && leftValue != -1)
    {
        treeNode *newNode = new treeNode(leftValue);
        root->leftChild = newNode;
        leftValue = -1;
    }
    if (root->data == key && root->rightChild == NULL && rightValue != -1)
    {
        treeNode *newNode = new treeNode(rightValue);
        root->rightChild = newNode;
        rightValue = -1;
    }
    insertNodeAtTree(root->leftChild, key, leftValue, rightValue);
    insertNodeAtTree(root->rightChild, key, leftValue, rightValue);
}

void inOrder(treeNode *root, string &str)
{
    if (root == NULL)
        return;
    inOrder(root->leftChild, str);
    str += to_string(root->data);
    inOrder(root->rightChild, str);
}

int findHeight(treeNode *root)
{
    if (root == NULL)
        return 0;
    int maxLevel = max(findHeight(root->leftChild), findHeight(root->rightChild));
    return 1 + maxLevel;
}

bool isSame(treeNode *root1, treeNode *root2)
{
    // Check tree structure
    if (findHeight(root1) != findHeight(root2))
        return false;
    // Check tree node value
    string str1 = "";
    string str2 = "";
    inOrder(root1, str1);
    inOrder(root2, str2);
    return str1.compare(str2) == 0;
}

void level_order(treeNode *root)
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
            cout << currNode->data << " ";
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

int main()
{
    int n;
    cin >> n;
    int firstRoot, firstLeft, firstRight;
    cin >> firstRoot >> firstLeft >> firstRight;
    treeNode *root = new treeNode(firstRoot);
    insertNodeAtTree(root, firstRoot, firstLeft, firstRight);

    for (int i = 1; i < n; i++)
    {
        int key, left, right;
        cin >> key >> left >> right;
        insertNodeAtTree(root, key, left, right);
    }

    level_order(root);
    printTree(root, n);

    return 0;
}
