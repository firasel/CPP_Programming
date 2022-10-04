#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string longestDiverseString(int a, int b, int c)
  {
    string s = "";
    int total = a + b + c;
    map<char, int> count;
    for (int i = 0; i < total; i++)
    {
      if ((a >= b && a >= c && count['a'] != 2) || ((count['b'] == 2 || count['c'] == 2) && a > 0))
      {
        s += "a";
        count['a']++;
        count['b'] = 0;
        count['c'] = 0;
        a--;
      }
      else if ((b >= a && b >= c && count['b'] != 2) || ((count['a'] == 2 || count['c'] == 2) && b > 0))
      {
        s += "b";
        count['a'] = 0;
        count['b']++;
        count['c'] = 0;
        b--;
      }
      else if ((c >= a && c >= b && count['c'] != 2) || ((count['a'] == 2 || count['b'] == 2) && c > 0))
      {
        s += "c";
        count['a'] = 0;
        count['b'] = 0;
        count['c']++;
        c--;
      }
    }
    return s;
  }
};

int main()
{
  Solution st;
  cout << st.longestDiverseString(1, 1, 7) << endl;
  return 0;
}
