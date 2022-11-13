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

class Solution
{
public:
  int subarrayLCM(vector<int> &nums, int k)
  {
    unsigned int ans = 0, size = nums.size();
    for (int i = 0; i < size; i++)
    {
      unsigned int temp = nums[i];
      for (int j = i; j < size; j++)
      {
        temp = lcm(temp, nums[j]);
        if (temp == k)
          ans++;
      }
    }
    return ans;
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
  vector<int> nums = {3, 6, 2, 7, 1};
  int res = st.subarrayLCM(nums, 6);
  cout << res << endl;
  return 0;
}