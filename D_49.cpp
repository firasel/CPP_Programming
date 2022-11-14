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

class MyLinkedList
{
  MyLinkedList *head;

public:
  int val;
  MyLinkedList *next;
  MyLinkedList()
  {
    head = NULL;
  }

  MyLinkedList(int val)
  {
    this->val = val;
    next = NULL;
  }

  int get(int index)
  {
    MyLinkedList *temp = head;
    int cnt = 0;
    while (index != cnt && temp)
      temp = temp->next, cnt++;
    if (temp)
      return temp->val;
    return -1;
  }

  void addAtHead(int val)
  {
    MyLinkedList *newNode = new MyLinkedList(val);
    newNode->next = head;
    head = newNode;
  }

  void addAtTail(int val)
  {
    if (head == NULL)
    {
      addAtHead(val);
      return;
    }
    MyLinkedList *temp = head;
    while (temp->next != NULL)
      temp = temp->next;
    MyLinkedList *newNode = new MyLinkedList(val);
    temp->next = newNode;
  }

  void addAtIndex(int index, int val)
  {
    if (index == 0)
    {
      addAtHead(val);
      return;
    }
    MyLinkedList *temp = head;
    int cnt = 1;
    while (cnt != index && temp)
      temp = temp->next, cnt++;
    if (temp == NULL)
      return;
    MyLinkedList *newNode = new MyLinkedList(val);
    newNode->next = temp->next;
    temp->next = newNode;
  }

  void deleteAtIndex(int index)
  {
    if (index == 0)
    {
      MyLinkedList *del = head;
      head = head->next;
      delete del;
      return;
    }
    MyLinkedList *temp = head;
    int cnt = 1;
    while (cnt != index && temp)
      temp = temp->next, cnt++;
    if (temp == NULL)
      return;
    MyLinkedList *del = temp->next;
    if (del == NULL)
      return;
    temp->next = temp->next->next;
    delete del;
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