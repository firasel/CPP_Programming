#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string.h>
#include <map>
#include <vector>
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
    int n, e, l;
    cin >> n >> e;
    map<int, vector<int>> levelShop;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        levelShop[a].push_back(b);
        levelShop[b].push_back(a);
    }

    cin >> l;
    map<int, bool> visited;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0] = true;

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        if (node.first == l)
        {
            cout << node.second << " ";
        }
        for (auto it : levelShop[node.second])
        {
            if (!visited[it])
            {
                visited[it] = true;
                q.push(make_pair((node.first + 1), it));
            }
        }
    }

    return 0;
}
