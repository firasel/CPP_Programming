#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

class Solution
{
public:
  int countTime(string time)
  {
    int h = 1, m = 1;
    if (time[0] == '?' && time[1] == '?')
      h = 24;
    else if (time[0] == '?')
    {
      int num = time[1] - '0';
      int count = 0;
      while (true)
      {
        int res = stoi(to_string(count) + to_string(num));
        if (res > 23)
          break;
        count++;
      }
      h = count;
    }
    else if (time[1] == '?')
    {
      if (time[0] == '2')
        h = 4;
      else
        h = 10;
    }

    if (time[3] == '?' && time[4] == '?')
      m = 60;
    else if (time[3] == '?')
    {
      int num = time[4] - '0';
      int count = 0;
      while (true)
      {
        int res = stoi(to_string(count) + to_string(num));
        if (res > 59)
          break;
        count++;
      }
      m = count;
    }
    else if (time[4] == '?')
      m = 10;

    return h * m;
  }
};

int main()
{
  Solution st;
  cout << st.countTime("?5:00") << endl;
  cout << st.countTime("0?:0?") << endl;
  cout << st.countTime("??:??") << endl;

  return 0;
}