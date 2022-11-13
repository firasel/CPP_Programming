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
  int listCheckAndCount(ListNode *head, int &len)
  {
    if (!head->next)
      return head->val;
    len += 1;
    return listCheckAndCount(head->next, len);
  }

  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    int len1 = 0, len2 = 0;
    if (listCheckAndCount(headA, len1) != listCheckAndCount(headB, len2))
      return NULL;
    while (len1 != len2)
    {
      if (len1 > len2)
      {
        headA = headA->next;
        len1--;
      }
      else if (len2 > len1)
      {
        headB = headB->next;
        len2--;
      }
    }
    while (headA != headB)
    {
      headA = headA->next;
      headB = headB->next;
    }
    return headA;
  }
};

int main()
{
  Solution st;
  ListNode *list_1 = new ListNode(4);
  ListNode *l1_2 = new ListNode(1);

  ListNode *list_2 = new ListNode(5);
  ListNode *l2_2 = new ListNode(6);
  ListNode *l2_3 = new ListNode(1);

  ListNode *l_3 = new ListNode(8);
  ListNode *l_4 = new ListNode(4);
  ListNode *l_5 = new ListNode(5);

  l_3->next = l_4;
  l_4->next = l_5;

  list_1->next = l1_2;
  l1_2->next = l_3;

  list_2->next = l2_2;
  l2_2->next = l2_3;
  l2_3->next = l_3;

  ListNode *res = st.getIntersectionNode(list_1, list_2);
  cout << (res ? res->val : 0) << endl;
  return 0;
}