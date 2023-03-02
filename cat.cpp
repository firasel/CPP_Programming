#include <bits/stdc++.h>
using namespace std;

int convert(char ch)
{
  if (ch == 'M' || ch == 'm')
    return 1;
  else if (ch == 'E' || ch == 'e')
    return 2;
  else if (ch == 'O' || ch == 'o')
    return 3;
  else if (ch == 'W' || ch == 'w')
    return 4;
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

    int prev = 0, flag = 0, cnt = 0;

    for (int i = 0; i < l; i++)
    {
      int temp = convert(str[i]);
      if (prev == temp)
        continue;
      if (temp == -1 || prev > temp)
      {
        flag = 1;
        break;
      }
      prev = temp;
      cnt++;
    }

    if (cnt == 4 && !flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}