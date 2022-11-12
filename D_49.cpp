#include <bits/stdc++.h>
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
  ListNode *head = NULL, *curr = NULL;

  void createNode(int num1, int num2, int &carr)
  {
    int sum = num1 + num2 + carr;
    carr = sum > 9 ? sum / 10 : 0;
    if (!head)
    {
      head = new ListNode(sum % 10);
      curr = head;
    }
    else
    {
      curr->next = new ListNode(sum % 10);
      curr = curr->next;
    }
  }

  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    head = NULL;
    int carr = 0;
    while (l1 && l2)
    {
      createNode(l1->val, l2->val, carr);
      l1 = l1->next;
      l2 = l2->next;
    }

    while (l1)
    {
      createNode(l1->val, 0, carr);
      l1 = l1->next;
    }

    while (l2)
    {
      createNode(l2->val, 0, carr);
      l2 = l2->next;
    }
    if (carr != 0)
      createNode(0, 0, carr);
    return head;
  }
};

void printLinkedList(ListNode *head)
{
  if (head == NULL)
    return;
  cout << head->val << " ";
  printLinkedList(head->next);
}

int main()
{
  Solution st;
  ListNode *list1 = new ListNode(2);
  ListNode *l1_1 = new ListNode(4);
  ListNode *l1_2 = new ListNode(3);

  list1->next = l1_1;
  l1_1->next = l1_2;

  ListNode *list2 = new ListNode(5);
  ListNode *l2_1 = new ListNode(6);
  ListNode *l2_2 = new ListNode(4);

  list2->next = l2_1;
  l2_1->next = l2_2;

  ListNode *res = st.addTwoNumbers(list1, list2);
  printLinkedList(res);
  cout << endl;
  return 0;
}