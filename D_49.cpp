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
  vector<double> convertTemperature(double celsius)
  {
    cout << setprecision(5) << fixed;
    return {celsius + 273.15, (celsius * 9 / 5) + 32};
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
  vector<double> res = st.convertTemperature(36.50);
  // printLinkedList(res);
  for (auto num : res)
    cout << num << endl;
  return 0;
}