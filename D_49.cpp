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
  string defangIPaddr(string address)
  {
    string ans = "";
    for (auto ch : address)
    {
      if (ch == '.')
        ans += "[.]";
      else
        ans += ch;
    }
    return ans;
  }
};

int main()
{
  Solution st;
  string res = st.defangIPaddr("255.100.50.0");
  cout << res << endl;

  return 0;
}