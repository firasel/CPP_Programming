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

void printList(ListNode *head)
{
  if (head == NULL)
    return;
  cout << head->val << " ";
  printList(head->next);
};

class Solution
{
public:
  int heightChecker(vector<int> &heights)
  {
    int cnt = 0, size = heights.size();
    vector<int> prev(heights.begin(), heights.end());
    sort(prev.begin(), prev.end());
    for (int i = 0; i < size; i++)
      if (heights[i] != prev[i])
        cnt++;
    return cnt;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {1, 1, 4, 2, 1, 3};

  int res = st.heightChecker(nums);
  cout << res << endl;
  return 0;
}