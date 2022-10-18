#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
  int t;
  string m;
  unordered_map<char, char> chMap;
  cin >> t >> m;
  char temp = 'a';
  for (auto ch : m)
  {
    chMap[temp] = ch;
    chMap[temp - 32] = ch - 32;
    temp++;
  }
  while (t--)
  {
    string str, res = "";
    cin >> str;
    for (auto ch : str)
    {
      if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        res += chMap[ch];
      else if (ch == '_')
        res += " ";
      else
        res += ch;
    }
    cout << res << endl;
  }
  return 0;
}