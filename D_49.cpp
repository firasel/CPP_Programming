#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int firstUniqChar(string s)
  {
    unordered_map<char, int> charMap;
    for (int i = 0; i < s.length(); i++)
    {
      if (charMap[s[i]] == 0)
      {
        size_t found = s.find(s[i], i + 1);
        if (found == string::npos)
          return i;
        charMap[s[i]]++;
      }
    }
    return -1;
  }
};

int main()
{
  Solution st;
  int res = st.firstUniqChar("aab");
  cout << res << endl;

  return 0;
}