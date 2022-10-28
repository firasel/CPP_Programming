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

void printList(ListNode *head)
{
  if (head == NULL)
    return;
  cout << head->val << " ";
  printList(head->next);
}

class Solution
{
public:
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    if (head == NULL)
      return head;
    int count = 0;
    ListNode *prevHead = head;
    ListNode *temp = head;
    stack<int> nums;
    while (temp != NULL)
    {
      nums.push(temp->val);
      if (++count == k)
      {
        count = 0;
        while (!nums.empty() && prevHead != NULL)
        {
          prevHead->val = nums.top();
          nums.pop();
          prevHead = prevHead->next;
        }
      }
      temp = temp->next;
    }
    return head;
  }
};

int main()
{
  ListNode *root = new ListNode(1);
  ListNode *node1 = new ListNode(2);
  ListNode *node2 = new ListNode(3);
  ListNode *node3 = new ListNode(4);
  ListNode *node4 = new ListNode(5);

  root->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;

  Solution st;
  ListNode *res = st.reverseKGroup(root, 3);
  printList(res);

  return 0;
}