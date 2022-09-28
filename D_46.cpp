#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        next = NULL;
    }
};

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    TreeNode *tHead = NULL;
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

    TreeNode *sortedListToBST(ListNode *head)
    {
        // if (head == NULL)
        //     return tHead;
        vector<int> nums = {1, 2, 3, 4, 5};
        // while (head != NULL)
        // {
        //     nums.push_back(head->val);
        //     head = head->next;
        // }
        createBST(nums, 0, nums.size());
        return tHead;
    }
};

int main()
{
    Solution st;
    st.sortedListToBST(NULL);
    return 0;
}
