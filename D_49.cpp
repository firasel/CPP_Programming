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
  bool hasCycle(ListNode *head)
  {
    ListNode *s = head;
    ListNode *f = head;
    while (f != NULL && f->next != NULL)
    {
      if (s->next == f->next->next)
        return true;
      s = s->next;
      f = f->next->next;
    }
    return false;
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
  ListNode *root = new ListNode(3);
  ListNode *node1 = new ListNode(2);
  ListNode *node2 = new ListNode(0);
  ListNode *node3 = new ListNode(4);

  root->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node1;

  Solution st;
  bool res = st.hasCycle(root);
  cout << res << endl;

  return 0;
}