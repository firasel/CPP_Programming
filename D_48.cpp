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
  int pairSum(ListNode *head)
  {
    int max = 0;
    vector<int> nums;
    while (head != NULL)
    {
      nums.push_back(head->val);
      head = head->next;
    }
    int size = nums.size();
    for (int i = 0; i < size / 2; i++)
    {
      if (max < (nums[i] + nums[size - 1 - i]))
        max = (nums[i] + nums[size - 1 - i]);
    }
    return max;
  }
};

int main()
{
  ListNode *head = new ListNode(5);
  ListNode *node1 = new ListNode(4);
  ListNode *node2 = new ListNode(2);
  ListNode *node3 = new ListNode(1);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;

  Solution st;
  int result = st.pairSum(head);
  cout << result << endl;
  return 0;
};
