#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

int main()
{
  int n;
  string s = "";
  stack<string> history;
  cin >> n;
  while (n)
  {
    int op;
    cin >> op;
    if (op == 1)
    {
      history.push(s);
      string temp;
      cin >> temp;
      s += temp;
    }
    else if (op == 2)
    {
      int len;
      cin >> len;
      history.push(s);
      s = s.substr(0, s.length() - len);
    }
    else if (op == 3)
    {
      int pos;
      cin >> pos;
      cout << s[pos - 1] << endl;
    }
    else if (op == 4)
    {
      if (!history.empty())
      {
        s = history.top();
        history.pop();
      }
    }
    n--;
  }

  return 0;
}