#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string.h>
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

void removeMaxToTree(TreeNode *&root, int &result)
{
    if (root == NULL)
        return;

    if (root->right != NULL && root->right->right != NULL)
    {
        removeMaxToTree(root->right, result);
    }
    else if (root->right != NULL)
    {
        TreeNode *del = root->right;
        result = del->val;
        root->right = del->left;
        delete del;
    }
    else if (root->right == NULL)
    {
        TreeNode *del = root;
        result = del->val;
        root = del->left;
        delete del;
    }
}

void insertNode(TreeNode *&root, int val)
{
    if (root == NULL)
    {
        root = new TreeNode(val);
        return;
    }

    if (root->val > val)
    {
        if (root->left)
            insertNode(root->left, val);
        else
        {
            root->left = new TreeNode(val);
        }
    }
    else
    {
        if (root->right)
            insertNode(root->right, val);
        else
        {
            root->right = new TreeNode(val);
        }
    }
}

string colorMixing(int n, string s)
{
    string result;
    int i = 0, j = 1;
    while (j < n)
    {
        if ((s[i] == 'R' && s[j] == 'B') || (s[i] == 'B' && s[j] == 'R'))
        {
            result += 'P';
            i++;
            j++;
        }
        else if ((s[i] == 'R' && s[j] == 'G') || (s[i] == 'G' && s[j] == 'R'))
        {
            result += 'Y';
            i++;
            j++;
        }
        else if ((s[i] == 'B' && s[j] == 'G') || (s[i] == 'G' && s[j] == 'B'))
        {
            result += 'C';
            i++;
            j++;
        }
        else if (s[i] != s[j])
        {
            result.push_back(s[i]);
            result.push_back(s[j]);
        }
        else if (s[i] == s[j])
        {
            i++;
            j++;
        }
        i++;
        j++;
    }
    if (n % 2 != 0)
        result += s[n - 1];
    return result;
}

int main()
{
    // int a;
    // cin >> a;
    // TreeNode *root = NULL;
    // insertNode(root, a);
    // queue<bool> treeQueue;
    // treeQueue.push(true);
    // while (!treeQueue.empty())
    // {
    //     treeQueue.pop();
    //     int x, y;
    //     cin >> x >> y;
    //     bool n1 = false;
    //     bool n2 = false;
    //     if (x != -1)
    //     {
    //         n1 = true;
    //         insertNode(root, x);
    //     }
    //     if (y != -1)
    //     {
    //         n2 = true;
    //         insertNode(root, y);
    //     }
    //     if (n1)
    //         treeQueue.push(n1);
    //     if (n2)
    //         treeQueue.push(n2);
    // }

    // int q;
    // cin >> q;
    // while (q)
    // {
    //     int op;
    //     cin >> op;
    //     if (op == 1)
    //     {
    //         int val;
    //         cin >> val;
    //         insertNode(root, val);
    //     }
    //     else if (op == 2)
    //     {
    //         int delValue;
    //         removeMaxToTree(root, delValue);
    //         cout << delValue << endl;
    //     }
    //     q--;
    // }

    int t;
    cin >> t;
    while (t)
    {
        int n;
        cin >> n;
        string s, result = "";
        cin >> s;
        result = colorMixing(n, s);
        result = colorMixing(result.size(), result);
        if (result != "")
            cout << result << endl;
        t--;
    }

    return 0;
}
