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
  void traverseList(ListNode *head, vector<int> &nums)
  {
    if (head == NULL)
      return;
    nums.push_back(head->val);
    traverseList(head->next, nums);
  }

  ListNode *makeLinkedList(vector<int> nums)
  {
    ListNode *head = NULL;
    ListNode *curr = NULL;
    for (auto num : nums)
    {
      if (head == NULL)
      {
        head = new ListNode(num);
        curr = head;
      }
      else
      {
        curr->next = new ListNode(num);
        curr = curr->next;
      }
    }
    return head;
  }

  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    vector<int> nums;
    for (auto head : lists)
      traverseList(head, nums);
    sort(nums.begin(), nums.end());
    return makeLinkedList(nums);
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
  ListNode *node1 = new ListNode(2);
  ListNode *node2 = new ListNode(6);
  ListNode *node3 = new ListNode(3);
  ListNode *node4 = new ListNode(4);

  root->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;

  ListNode *root2 = new ListNode(1);
  ListNode *node2_1 = new ListNode(2);
  ListNode *node2_2 = new ListNode(6);
  ListNode *node2_3 = new ListNode(3);

  root2->next = node2_1;
  node2_1->next = node2_2;
  node2_2->next = node2_3;

  Solution st;
  vector<ListNode *> lists = {root, root2};
  ListNode *res = st.mergeKLists(lists);
  printList(res);

  return 0;
}