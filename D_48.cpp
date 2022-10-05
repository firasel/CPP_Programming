#include <bits/stdc++.h>
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
  ListNode *swapNodes(ListNode *head, int k)
  {
    vector<ListNode *> lists;
    while (head != NULL)
    {
      lists.push_back(head);
      head = head->next;
    }
    int size = lists.size();
    swap(lists[k - 1], lists[size - k]);
    lists[size - 1]->next = NULL;
    for (int i = 0; i < size - 1; i++)
    {
      lists[i]->next = lists[i + 1];
    }
    return lists[0];
  }
};

void printList(ListNode *head)
{
  if (head == NULL)
    return;
  cout << head->val << " ";
  printList(head->next);
}

int main()
{
  ListNode *head = new ListNode(1);
  ListNode *node1 = new ListNode(2);
  ListNode *node2 = new ListNode(3);
  ListNode *node3 = new ListNode(4);
  ListNode *node4 = new ListNode(5);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;

  Solution st;
  st.swapNodes(head, 2);
  printList(head);
  cout << endl;
  return 0;
};
