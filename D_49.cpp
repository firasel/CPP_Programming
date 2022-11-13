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
  ListNode *deleteDuplicates(ListNode *head)
  {
    if (head == NULL || head->next == NULL)
      return head;
    ListNode *prev = NULL, *curr = head, *next = head->next;
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
  Solution st;
  ListNode *list_1 = new ListNode(1);
  ListNode *l1_2 = new ListNode(2);
  ListNode *l1_3 = new ListNode(3);
  ListNode *l1_4 = new ListNode(3);
  ListNode *l1_5 = new ListNode(4);
  ListNode *l1_6 = new ListNode(4);
  ListNode *l1_7 = new ListNode(5);

  list_1->next = l1_2;
  l1_2->next = l1_3;
  l1_3->next = l1_4;
  l1_4->next = l1_5;
  l1_5->next = l1_6;
  l1_6->next = l1_7;

  ListNode *res = st.deleteDuplicates(list_1);
  printLinkedList(res);
  cout << endl;

  return 0;
}