#include <bits/stdc++.h>
#include <iostream>
#include <numeric>

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

void printList(ListNode *head)
{
  if (head == NULL)
    return;
  cout << head->val << " ";
  printList(head->next);
};

class Solution
{
public:
  ListNode *oddEvenList(ListNode *head)
  {
    if (!head || !head->next)
      return head;
    ListNode *node = head, *last = head, *temp, *end;
    while (last->next && last->next->next)
      last = last->next->next;

    end = last;
    while (node != end)
    {
      temp = node->next;
      node->next = temp->next;
      temp->next = last->next;
      last->next = temp;
      last = last->next;
      node = node->next;
    }
    return head;
  }
};

int main()
{
  Solution st;
  ListNode *head = new ListNode(1);
  ListNode *val1 = new ListNode(2);
  ListNode *val2 = new ListNode(3);
  ListNode *val3 = new ListNode(4);
  ListNode *val4 = new ListNode(5);
  head->next = val1;
  val1->next = val2;
  val2->next = val3;
  val3->next = val4;

  ListNode *res = st.oddEvenList(head);
  printList(res);
  cout << endl;
  return 0;
}