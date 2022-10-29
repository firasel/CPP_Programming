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
  // string longestPalindrome(string s)
  // {
  //   string temp = s;
  //   reverse(temp.begin(), temp.end());
  //   if (temp == s)
  //     return s;
  //   else if (s.length() > 2)
  //   {
  //     temp = longestPalindrome(s.substr(0, s.length() - 2));
  //     temp = longestPalindrome(s.substr(1));
  //   }
  //   return temp;
  // }
  string oddString(vector<string> &words)
  {
    vector<string> nums;
    for (auto word : words)
    {
      string str = "";
      for (int i = 0; i < word.length() - 1; i++)
      {
        str += to_string((97 - word[i + 1]) - (97 - word[i])) + '_';
      }
      nums.push_back(str);
    }
    cout << endl;
    for (auto num : nums)
      cout << num << " ";
    cout << endl;
    string res = nums[0];
    int index = 0;
    for (int i = 1; i < nums.size() - 1; i++)
    {
      if (nums[i] != nums[i + 1])
      {
        if (res == nums[i])
        {
          index = i + 1;
          res = nums[i++ + 1];
        }
        else
        {
          index = i;
          res = nums[i];
        }
      }
    }

    return words[index];
  }
};

int main()
{
  Solution st;
  string str = "cbbd";
  vector<string> words = {"adc", "wzy", "abc"};
  string res = st.oddString(words);
  cout << res << endl;

  return 0;
}