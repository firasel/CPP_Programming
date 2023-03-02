#include <bits/stdc++.h>
using namespace std;

bool m = false, e = false, o = false, w = false;

int convert(char ch)
{
  if (ch == 'M' || ch == 'm')
  {
    m = true;
    return 1;
  }
  else if (ch == 'E' || ch == 'e')
  {
    e = true;
    return 2;
  }
  else if (ch == 'O' || ch == 'o')
  {
    o = true;
    return 3;
  }
  else if (ch == 'W' || ch == 'w')
  {
    w = true;
    return 4;
  }
  return -1;
}
// meow meow
int main()
{
  int t, l;
  cin >> t;
  while (t--)
  {
    cin >> l;
    string str;
    cin >> str;

    int prev = 0, flag = 0;
    for (int i = 0; i < l; i++)
    {
      int temp = convert(str[i]);
      if (temp == -1 || prev > temp)
      {
        flag = 1;
        break;
      }
      prev = temp;
    }
    if (m && e && o && w && flag == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;

    m = false;
    e = false;
    o = false;
    w = false;
  }
  return 0;
}