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
void inOrder(treeNode *root, string &chk);
void preOrder(treeNode *root, string &chk);
void postOrder(treeNode *root, string &chk);
int searchInOrder(int inOrderArr[], int current, int start, int end);
treeNode *buildTreePreIn(int preOrderArr[], int inOrderArr[], int start, int end);

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

void inOrder(treeNode *root, string &chk)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->leftChild, chk);
    chk += to_string(root->data);
    inOrder(root->rightChild, chk);
}

void preOrder(treeNode *root, string &chk)
{
    if (root == NULL)
    {
        return;
    }
    chk += to_string(root->data);
    preOrder(root->leftChild, chk);
    preOrder(root->rightChild, chk);
}

void postOrder(treeNode *root, string &chk)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->leftChild, chk);
    postOrder(root->rightChild, chk);
    chk += to_string(root->data);
}

void inOrderPosition(treeNode *root, int k)
{
    static int count = 0;
    if (root == NULL)
    {
        return;
    }

    cout << "Cnt: " << count << endl;
    if (count <= k)
    {
        inOrderPosition(root->leftChild, k);
        count++;
        if (count == k)
        {
            cout << "Position " << k << " Value is: " << root->data << endl;
            return;
        }
        inOrderPosition(root->rightChild, k);
    }
}

int levelOrderTraversal(treeNode *root, string &chk, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    int level = 0;
    queue<treeNode *> q;
    q.push(root);
    q.push(NULL);
    int max = INT_MIN;

    while (!q.empty())
    {
        treeNode *chkNode = q.front();
        q.pop();
        if (chkNode != NULL)
        {
            if (level == k && max < chkNode->data)
            {
                max = chkNode->data;
            }
            cout << chkNode->data << " ";
            chk += to_string(chkNode->data);
            if (chkNode->leftChild != NULL)
            {
                q.push(chkNode->leftChild);
            }

            if (chkNode->rightChild != NULL)
            {
                q.push(chkNode->rightChild);
            }
        }
        else
        {
            if (!q.empty())
            {
                q.push(NULL);
                level++;
            }
        }
    }
    return max;
}

int searchInOrder(int inOrderArr[], int current, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (inOrderArr[i] == current)
            return i;
    }
    return -1;
}

treeNode *buildTreePreIn(int preOrderArr[], int inOrderArr[], int start, int end)
{
    static int id = 0;
    int current = preOrderArr[id];
    id++;
    treeNode *newNode = new treeNode(current);
    if (start == end)
    {
        return newNode;
    }
    int pos = searchInOrder(inOrderArr, current, start, end);
    newNode->leftChild = buildTreePreIn(preOrderArr, inOrderArr, start, pos - 1);
    newNode->rightChild = buildTreePreIn(preOrderArr, inOrderArr, pos + 1, end);
    return newNode;
}

void printLeaves(treeNode *root)
{
    if (root == NULL)
        return;
    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        cout << root->data << " ";
        return;
    }
    printLeaves(root->leftChild);
    printLeaves(root->rightChild);
}

void printLeftNonLeaves(treeNode *root)
{
    if (root == NULL)
        return;
    if (root->leftChild != NULL)
    {
        cout << root->data << " ";
        printLeftNonLeaves(root->leftChild);
    }
    else if (root->rightChild != NULL)
    {
        cout << root->data << " ";
        printLeftNonLeaves(root->rightChild);
    }
}

void printRightNonLeaves(treeNode *root)
{
    if (root == NULL)
        return;
    if (root->rightChild != NULL)
    {
        cout << root->data << " ";
        printRightNonLeaves(root->rightChild);
    }
    else if (root->leftChild != NULL)
    {
        cout << root->data << " ";
        printRightNonLeaves(root->leftChild);
    }
}

void boundaryTraversal(treeNode *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";

    printLeftNonLeaves(root->leftChild);
    printLeaves(root->leftChild);
    printLeaves(root->rightChild);
    printRightNonLeaves(root->rightChild);
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
    }
    if (root->data == key && root->rightChild == NULL && rightValue != -1)
    {
        treeNode *newNode = new treeNode(rightValue);
        root->rightChild = newNode;
    }
    insertNodeAtTree(root->leftChild, key, leftValue, rightValue);
    insertNodeAtTree(root->rightChild, key, leftValue, rightValue);
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

    printTree(root, n);
    return 0;
}

/*

9
0 1 3 4 2 5 7 8 6
3 1 4 0 7 5 8 2 6

9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1

7
0 3 6
3 4 8
6 9 2
4 -1 -1
8 -1 -1
9 -1 -1
2 -1 -1

5 4
0 1 2
1 3 4
2 -1 -1
3 -1 -1
4 -1 -1

5
1 2 3
2 4 5
3 -1 -1
4 -1 -1
5 -1 -1


*/
