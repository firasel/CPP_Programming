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

// void inOrder(treeNode *root, queue<int> &qu)
// {
//     if (root == NULL)
//         return;
//     if (root != NULL && (root->leftChild == NULL && root->rightChild != NULL))
//     {
//         qu.push(-101);
//     }
//     qu.push(root->data);
//     inOrder(root->leftChild, qu);
//     if (root != NULL && (root->leftChild != NULL && root->rightChild == NULL))
//     {
//         qu.push(-101);
//     }
//     inOrder(root->rightChild, qu);
// }

// bool isSymmetric(treeNode *root)
// {
//     queue<int> qu1;
//     queue<int> qu2;
//     inOrder(root->leftChild, qu1);
//     inOrder(root->rightChild, qu2);

//     stack<int> st2;
//     while (!qu2.empty())
//     {
//         st2.push(qu2.front());
//         qu2.pop();
//     }
//     while (!st2.empty())
//     {
//         qu2.push(st2.top());
//         st2.pop();
//     }

//     // while (!qu1.empty())
//     // {
//     //     cout << qu1.front() << " ";
//     //     qu1.pop();
//     // }
//     // cout << endl;

//     // while (!qu2.empty())
//     // {
//     //     cout << qu2.front() << " ";
//     //     qu2.pop();
//     // }
//     // cout << endl;

//     while (!qu1.empty() && !qu2.empty())
//     {
//         if (qu1.front() != qu2.front())
//             return false;
//         qu1.pop();
//         qu2.pop();
//     }

//     if (qu1.empty() != qu2.empty())
//         return false;

//     return true;
// }

void inOrder(treeNode *root, queue<int> &qu)
{
    if (root == NULL)
        return;
    if (root != NULL && (root->leftChild == NULL && root->rightChild != NULL))
    {
        qu.push(-101);
    }
    inOrder(root->leftChild, qu);
    qu.push(root->data);
    if (root != NULL && (root->leftChild != NULL && root->rightChild == NULL))
    {
        qu.push(-101);
    }
    inOrder(root->rightChild, qu);
}
bool isSymmetric(treeNode *root)
{
    queue<int> qu1;
    queue<int> qu2;
    inOrder(root->leftChild, qu1);
    inOrder(root->rightChild, qu2);

    stack<int> st2;
    while (!qu2.empty())
    {
        st2.push(qu2.front());
        qu2.pop();
    }
    while (!st2.empty())
    {
        qu2.push(st2.top());
        st2.pop();
    }

    while (!qu1.empty() && !qu2.empty())
    {
        if (qu1.front() != qu2.front())
            return false;
        qu1.pop();
        qu2.pop();
    }

    if (qu1.empty() != qu2.empty())
        return false;

    return true;
}

void zigzag_order(treeNode *root)
{
    if (root == NULL)
        return;
    queue<treeNode *> qu;
    qu.push(root);
    qu.push(NULL);
    static bool printCondition = false;

    while (!qu.empty())
    {
        treeNode *chkNode = qu.front();
        qu.pop();
        if (chkNode != NULL)
        {
            cout << chkNode->data << " ";
            if (printCondition)
            {
                printCondition = false;
                if (chkNode->leftChild != NULL)
                    qu.push(chkNode->leftChild);
                if (chkNode->rightChild != NULL)
                    qu.push(chkNode->rightChild);
            }
            else
            {
                printCondition = true;
                if (chkNode->rightChild != NULL)
                    qu.push(chkNode->rightChild);
                if (chkNode->leftChild != NULL)
                    qu.push(chkNode->leftChild);
            }
        }
        else if (!qu.empty())
            qu.push(NULL);
    }
}

int main()
{
    int n;
    cin >> n;
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

    // printTree(root, n);
    // level_order(root->leftChild);
    // cout << endl;
    // level_order(root->rightChild);
    // cout << endl;
    zigzag_order(root);

    return 0;
}
