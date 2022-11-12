#include <bits/stdc++.h>
#include <string.h>
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
  int distinctAverages(vector<int> &nums)
  {
    unordered_set<float> uniNum;
    sort(nums.begin(), nums.end());
    int s = 0, e = nums.size() - 1;
    while (s < e)
    {
      uniNum.insert(((float)nums[s] + (float)nums[e]) / 2);
      s++, e--;
    }
    return uniNum.size();
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
  vector<int> nums = {9, 5, 7, 8, 7, 9, 8, 2, 0, 7};
  int res = st.distinctAverages(nums);
  // printLinkedList(res);
  cout << res << endl;
  return 0;
}