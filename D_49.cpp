#include <bits/stdc++.h>
#include <iostream>
#include <numeric>

using namespace std;

class Solution
{
public:
  string minRemoveToMakeValid(string s)
  {
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
      char temp = s[i];
      if (temp == '(' || temp == ')')
      {
        if (temp == '(')
          st.push(temp);
        else if (!st.empty() && st.top() == '(')
        {
          st.pop();
        }
        else
        {
          s.erase(i, 1);
          i--;
        }
      }
    }
    while (!st.empty())
    {
      s.erase(s.find_last_of(st.top()), 1);
      st.pop();
    }

    return s;
  }
};

int main()
{
  Solution st;
  string res = st.minRemoveToMakeValid("a)b(c)d))((le(et))");
  cout << res << endl;
  return 0;
}