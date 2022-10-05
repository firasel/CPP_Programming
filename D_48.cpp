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
  int numComponents(ListNode *head, vector<int> &nums)
  {
    int count = 0;
    bool prev = false;
    while (head != NULL)
    {
      bool found = false;
      for (auto i : nums)
      {
        if (i == head->val)
        {
          found = true;
          prev = true;
          break;
        }
      }
      if (prev && !found)
      {
        count++;
        prev = false;
      }
      head = head->next;
    }
    if (prev)
      count++;
    return count;
  }
};

int main()
{
  ListNode *head = new ListNode(0);
  ListNode *node1 = new ListNode(1);
  ListNode *node2 = new ListNode(2);
  ListNode *node3 = new ListNode(3);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;

  Solution st;
  vector<int> nums = {0, 1, 3};
  int result = st.numComponents(head, nums);
  cout << result << endl;
  return 0;
};
