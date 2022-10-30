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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    map<ListNode *, int> nodesList;
    while (headA != NULL)
    {
      nodesList[headA]++;
      headA = headA->next;
    }

    while (headB != NULL)
    {
      nodesList[headB]++;
      headB = headB->next;
    }

    for (auto node : nodesList)
    {
      if (node.second == 2)
        return node.first;
    }
    return NULL;
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
  ListNode *root = new ListNode(1);
  ListNode *node1 = new ListNode(9);
  ListNode *node2 = new ListNode(1);
  ListNode *node3 = new ListNode(2);
  ListNode *node4 = new ListNode(4);
  ListNode *node5 = new ListNode(3);
  root->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node5->next = node3;

  Solution st;
  ListNode *res = st.getIntersectionNode(root, node5);
  if (res)
    cout << res->val << endl;
  printList(root);
  cout << endl;
  printList(node5);
  cout << endl;
  return 0;
};
