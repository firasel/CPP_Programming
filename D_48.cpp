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
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
  {
    ListNode *prev = NULL;
    ListNode *curr = list1;
    ListNode *start;
    ListNode *end;
    int count = 0;

    while (curr != NULL)
    {
      if (count == a)
        start = prev;
      if (count == b)
      {
        end = curr->next;
        break;
      }
      prev = curr;
      curr = curr->next;
      count++;
    }

    if (start)
      start->next = list2;
    else
      list1 = list2;
    while (list2->next != NULL)
      list2 = list2->next;
    list2->next = end;

    return list1;
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
  ListNode *head = new ListNode(0);
  ListNode *node1 = new ListNode(1);
  ListNode *node2 = new ListNode(2);
  ListNode *node3 = new ListNode(3);
  ListNode *node4 = new ListNode(4);
  ListNode *node5 = new ListNode(5);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;

  ListNode *head2 = new ListNode(10);
  ListNode *node2_1 = new ListNode(15);
  ListNode *node2_2 = new ListNode(20);
  head2->next = node2_1;
  node2_1->next = node2_2;

  Solution st;
  ListNode *result = st.mergeInBetween(head, 3, 4, head2);
  printList(result);
  cout << endl;
  return 0;
};
