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
    // levelShop[0].push_back(0);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        int level = -1;
        for (auto shops : levelShop)
            for (int shop : shops.second)
                if (shop == a)
                    level = shops.first;
        if (level == -1)
        {
            levelShop[0].push_back(a);
            level = 0;
        }
        levelShop[level + 1].push_back(b);
    }

    cin >> l;
    sort(levelShop[l].begin(), levelShop[l].end());
    map<int, bool> visited;
    for (int shop : levelShop[l])
    {
        if (visited[shop] != true)
        {
            cout << shop << " ";
            visited[shop] = true;
        }
    }
    cout << endl;
    for (auto element : levelShop)
    {
        cout << element.first << ": ";
        for (int i : element.second)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
