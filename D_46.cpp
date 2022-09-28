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

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = head->next;
        int dt;
        while (curr != NULL)
        {
            if (next != NULL && curr->val == next->val)
            {
                ListNode *temp = next->next;
                ListNode *del1 = curr;
                ListNode *del2 = next;
                if (prev != NULL)
                    prev->next = temp;
                else
                    head = temp;
                curr = temp;
                next = temp != NULL ? temp->next : temp;
                dt = del1->val;
                delete del1;
                delete del2;
            }
            else if (dt == curr->val)
            {
                ListNode *temp = curr->next;
                ListNode *del1 = curr;
                if (prev != NULL)
                    prev->next = temp;
                else
                    head = temp;
                curr = temp;
                next = temp != NULL ? temp->next : temp;
                delete del1;
            }
            else
            {
                prev = curr;
                curr = next;
                next = next != NULL ? next->next : next;
            }
        }
        return head;
    }
};

int main()
{
    return 0;
}
