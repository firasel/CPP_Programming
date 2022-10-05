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
  void deleteNode(ListNode *node)
  {
    ListNode *del = node->next;
    node->val = node->next->val;
    node->next = del->next;
    delete del;
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
  ListNode *head = new ListNode(4);
  ListNode *node1 = new ListNode(5);
  ListNode *node2 = new ListNode(1);
  ListNode *node3 = new ListNode(9);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;

  Solution st;
  st.deleteNode(node1);
  printList(head);
  cout << endl;
  return 0;
};
