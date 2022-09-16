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
    vector<int> numsArr;
    void inOrder(TreeNode *root)
    {
        if (root->left)
            inOrder(root->left);
        numsArr.push_back(root->val);
        if (root->right)
            inOrder(root->right);
    }
    TreeNode *createBST(vector<int> nums, int start, int end)
    {
        if (start >= end)
            return NULL;
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = createBST(nums, start, mid);
        root->right = createBST(nums, mid + 1, end);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        TreeNode *root;
        if (nums.size() == 0)
            return root;
        root = createBST(nums, 0, nums.size());
        return root;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == NULL)
            return result;
        stack<TreeNode *> current;
        stack<TreeNode *> next;
        bool leftToRight = true;
        current.push(root);
        vector<int> levelVect;
        while (!current.empty())
        {
            TreeNode *temp = current.top();
            current.pop();
            levelVect.push_back(temp->val);
            if (leftToRight)
            {
                if (temp->left)
                    next.push(temp->left);
                if (temp->right)
                    next.push(temp->right);
            }
            else
            {
                if (temp->right)
                    next.push(temp->right);
                if (temp->left)
                    next.push(temp->left);
            }
            if (current.empty())
            {
                leftToRight = !leftToRight;
                result.push_back(levelVect);
                levelVect.clear();
                swap(current, next);
            }
        }
        return result;
    }
};

void inOrder(TreeNode *root, string &chk)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left, chk);
    chk += to_string(root->val) + " ";
    inOrder(root->right, chk);
}

void preOrder(TreeNode *root, string &chk)
{
    if (root == NULL)
    {
        return;
    }
    chk += to_string(root->val) + " ";
    preOrder(root->left, chk);
    preOrder(root->right, chk);
}

void postOrder(TreeNode *root, string &chk)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left, chk);
    postOrder(root->right, chk);
    chk += to_string(root->val) + " ";
}

int levelOrderTraversal(TreeNode *root, string &chk, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    int level = 0;
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    int max = INT_MIN;

    while (!q.empty())
    {
        TreeNode *chkNode = q.front();
        q.pop();
        if (chkNode != NULL)
        {
            if (level == k && max < chkNode->val)
            {
                max = chkNode->val;
            }
            chk += to_string(chkNode->val) + " ";
            if (chkNode->left != NULL)
            {
                q.push(chkNode->left);
            }

            if (chkNode->right != NULL)
            {
                q.push(chkNode->right);
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

int maxDepth(TreeNode *node)
{
    if (node == NULL)
        return -1;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

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
    // vector<int> nums = {0, 1, 2, 3, 4, 5};
    // TreeNode *root2 = st.sortedArrayToBST(nums);

    string str1 = "";
    string str2 = "";
    string str3 = "";
    string str4 = "";

    inOrder(root, str1);
    preOrder(root, str2);
    postOrder(root, str3);
    levelOrderTraversal(root, str4, 0);

    cout << endl
         << "In: " << str1 << endl
         << endl;
    cout << "Pre: " << str2 << endl
         << endl;
    cout << "Post: " << str3 << endl
         << endl;
    cout << "Level: " << str4 << endl
         << endl;

    cout << "Height of tree is " << maxDepth(root);

    // TreeNode *root2 = st.pruneTree(root);
    printTree(root, 0);
    // printTree(root2, 0);

    return 0;
}
