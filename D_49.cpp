#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
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
  ListNode *deleteMiddle(ListNode *head)
  {
    ListNode *slow = head, *fast = head, *prev = head;
    while (fast && fast->next != NULL)
    {
      prev = slow;
      slow = slow->next;
      if (fast->next)
        fast = fast->next->next;
    }
    if (prev == slow)
      return NULL;
    prev->next = slow->next;
    delete slow;
    return head;
  }
};

int main()
{
  ListNode *head = new ListNode(1);
  ListNode *node2 = new ListNode(2);
  ListNode *node3 = new ListNode(3);
  ListNode *node4 = new ListNode(4);
  head->next = node2;
  node2->next = node3;
  node3->next = node4;

  Solution st;
  ListNode *res = st.deleteMiddle(head);
  while (res)
  {
    cout << res->val << " ";
    res = res->next;
  }
  cout << endl;

  return 0;
}