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

  ListNode *reverseKGroup(ListNode *head, int k)
  {
    if (k < 2)
      return head;
    int cnt = 1;
    ListNode *temp = head, *prev = head, *lastPrev = NULL, *next = NULL, *ans = NULL;
    while (temp)
    {
      cnt++;
      temp = temp->next;
      if (cnt == k && temp)
      {
        if (!ans)
          ans = temp;
        next = temp->next;
        ListNode *curr = reverseList(prev, next);
        if (lastPrev)
          lastPrev->next = temp;
        curr->next = next;
        lastPrev = curr;
        prev = next;
        temp = curr;
        cnt = 0;
      }
    }
    return ans;
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

  ListNode *res = st.reverseKGroup(list1, 3);
  printLinkedList(res);
  cout << endl;
  return 0;
}