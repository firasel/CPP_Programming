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

void printLinkedList(ListNode *head)
{
  if (head == NULL)
    return;
  cout << head->val << " ";
  printLinkedList(head->next);
}

class Solution
{
public:
  ListNode *reverseList(ListNode *head, ListNode *endNode)
  {
    ListNode *prev = NULL, *curr = head, *next = NULL, *ans = head;
    while (curr && curr != endNode)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return ans;
  }

  void reorderList(ListNode *head)
  {
    if (!head)
      return;
    ListNode *temp = head, *next = NULL, *prevLast = NULL, *last = NULL;
    while (temp)
    {
      last = temp;
      next = temp->next;
      while (last->next)
      {
        prevLast = last;
        last = last->next;
      }
      if (temp == last)
        break;
      if (prevLast)
        prevLast->next = NULL;
      if (last && last != next)
        last->next = next;
      temp->next = last;
      if (temp->next)
        temp = temp->next->next;
      else
        break;
    }
  }
};

int main()
{
  Solution st;
  ListNode *list1 = new ListNode(1);
  ListNode *l2 = new ListNode(2);
  ListNode *l3 = new ListNode(3);
  ListNode *l4 = new ListNode(4);
  ListNode *l5 = new ListNode(5);

  list1->next = l2;
  l2->next = l3;
  l3->next = l4;
  // l4->next = l5;

  st.reorderList(list1);
  printLinkedList(list1);
  cout << endl;
  return 0;
}