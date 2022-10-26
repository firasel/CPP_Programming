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
  ListNode *head = NULL;

  void insertAtTail(int val)
  {
    ListNode *newNode = new ListNode(val);
    if (head == NULL)
      head = newNode;
    else
    {
      ListNode *temp = head;
      while (temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }

  void remainderList(ListNode *node)
  {
    while (node != NULL)
    {
      insertAtTail(node->val);
      node = node->next;
    }
  }

  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    ListNode *a = list1;
    ListNode *b = list2;
    while (a != NULL && b != NULL)
    {
      if (a->val <= b->val)
      {
        insertAtTail(a->val);
        a = a->next;
      }
      else
      {
        insertAtTail(b->val);
        b = b->next;
      }
    }
    remainderList(a);
    remainderList(b);
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
  ListNode *root1 = new ListNode(1);
  ListNode *node1_1 = new ListNode(2);
  ListNode *node1_2 = new ListNode(4);

  ListNode *root2 = new ListNode(2);
  ListNode *node2_1 = new ListNode(4);
  ListNode *node2_2 = new ListNode(3);
  root1->next = node1_1;
  node1_1->next = node1_2;

  root2->next = node2_1;
  node2_1->next = node2_2;

  Solution st;
  ListNode *res = st.mergeTwoLists(root1, root2);
  printList(res);

  return 0;
}