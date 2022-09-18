#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int v)
    {
        val = v;
        next = NULL;
    }
};

class Solution
{
public:
    ListNode *head = NULL;
    void insertNode(ListNode *&head, int num)
    {
        if (head == NULL)
        {
            head = new ListNode(num);
            return;
        }
        ListNode *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new ListNode(num);
    }

    void linkedListSum(int extra, ListNode *l1, ListNode *l2)
    {
        if (extra < 0 && !l1 && !l2)
            return;
        extra = (extra == -1 ? 0 : extra) + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        cout << extra << endl;

        if (extra < 10)
        {
            insertNode(head, extra);
            extra = -1;
            linkedListSum(extra, l1->next, l2->next);
        }
        else
        {
            int lastNum = extra % 10;
            insertNode(head, lastNum);
            extra /= 10;
            linkedListSum(extra, l1->next, l2->next);
        }
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        head = NULL;
        linkedListSum(0, l1, l2);
        return head;
    }
};

int main()
{

    ListNode *l1 = new ListNode(2);
    ListNode *l1N = new ListNode(4);
    ListNode *l1NN = new ListNode(3);
    l1->next = l1N;
    l1N->next = l1NN;

    ListNode *l2 = new ListNode(5);
    ListNode *l2N = new ListNode(6);
    ListNode *l2NN = new ListNode(4);
    l2->next = l2N;
    l2N->next = l2NN;

    Solution sc;
    ListNode *head = sc.addTwoNumbers(l1, l2);
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}