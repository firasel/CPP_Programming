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

void printLinkedList(ListNode *head)
{
  if (head == NULL)
    return;
  cout << head->val << " ";
  printLinkedList(head->next);
}

class Solution
{
public:
  string reverseWords(string s)
  {
    string ans = "", temp = " ";
    for (auto ch : s)
    {
      if (ch != ' ')
        temp += ch;
      else if (ch == ' ' && temp != "" && temp != " ")
      {
        ans = temp + ans;
        temp = " ";
      }
    }
    if (temp != "")
      ans = temp + ans;
    while (ans[0] == ' ')
      ans.erase(0, 1);
    return ans;
  }
};

int main()
{
  Solution st;
  string res = st.reverseWords("the sky is blue");
  cout << res << endl;
  return 0;
}