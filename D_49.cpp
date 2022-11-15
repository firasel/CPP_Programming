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
  void reorderList(ListNode *head)
  {
    ListNode *temp = head, *next = NULL;
    stack<ListNode *> listSt;
    while (temp)
      listSt.push(temp), temp = temp->next;
    temp = head;
    while (temp)
    {
      if (temp == listSt.top())
      {
        temp->next = NULL;
        break;
      }
      next = temp->next;
      temp->next = listSt.top();
      listSt.top()->next = next;
      if (next == listSt.top())
      {
        next->next = NULL;
        break;
      }
      listSt.pop();
      temp = next;
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
  l4->next = l5;

  st.reorderList(list1);
  printLinkedList(list1);
  cout << endl;
  return 0;
}