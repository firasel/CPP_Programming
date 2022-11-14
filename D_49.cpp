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
  ListNode *swapPairs(ListNode *head)
  {
    ListNode *prev = NULL, *temp1 = head, *temp2 = NULL, *temp = NULL, *res = NULL;
    while (temp1 && temp1->next)
    {
      temp2 = temp1->next;
      temp = temp2->next;
      temp2->next = temp1;
      temp1->next = temp;
      if (prev)
        prev->next = temp2;
      if (!res)
        res = temp2;
      prev = temp1;
      temp1 = temp;
    }
    if (res)
      return res;
    return head;
  }
};

int main()
{
  Solution st;
  ListNode *list1 = new ListNode(1);
  ListNode *l2 = new ListNode(2);
  ListNode *l3 = new ListNode(3);
  ListNode *l4 = new ListNode(4);

  list1->next = l2;
  l2->next = l3;
  l3->next = l4;

  ListNode *res = st.swapPairs(list1);
  printLinkedList(res);
  cout << endl;
  return 0;
}