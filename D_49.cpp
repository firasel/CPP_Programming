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
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> strMap;
    string tempStr;
    for (int i = 0; i < strs.size(); i++)
    {
      tempStr = strs[i];
      sort(strs[i].begin(), strs[i].end());
      strMap[strs[i]].push_back(tempStr);
    }
    for (auto i : strMap)
      res.push_back(i.second);
    return res;
  }
};

int main()
{
  Solution st;
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> res = st.groupAnagrams(strs);
  for (auto allStr : res)
  {
    for (auto str : allStr)
    {
      cout << str << " ";
    }
    cout << endl;
  }

  return 0;
}