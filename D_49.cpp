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
  ListNode *removeElements(ListNode *head, int val)
  {
    if (head == NULL)
      return head;
    ListNode *prev = NULL;
    ListNode *temp = head;
    while (temp != NULL)
    {
      if (temp->val == val)
      {
        if (prev == NULL)
        {
          ListNode *del = temp;
          head = head->next;
          temp = temp->next;
          delete del;
        }
        else
        {
          ListNode *del = temp;
          prev->next = temp->next;
          temp = temp->next;
          delete del;
        }
      }
      else
      {
        prev = temp;
        temp = temp->next;
      }
    }
    return head;
  }
};

void printList(ListNode *head)
{
  if (head == NULL)
    return;
  cout << head->val << " ";
  printList(head->next);
}

int main()
{
  ListNode *root = new ListNode(1);
  ListNode *node1 = new ListNode(2);
  ListNode *node2 = new ListNode(6);
  ListNode *node3 = new ListNode(3);
  ListNode *node4 = new ListNode(4);
  ListNode *node5 = new ListNode(5);
  ListNode *node6 = new ListNode(6);

  root->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  node5->next = node6;

  Solution st;
  ListNode *res = st.removeElements(root, 6);
  printList(res);

  return 0;
}