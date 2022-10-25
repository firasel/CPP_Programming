#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canConstruct(string ransomNote, string magazine)
  {
    if (ransomNote == magazine)
      return true;
    if (ransomNote.length() > magazine.length())
      return false;
    for (auto ch : ransomNote)
    {
      size_t found = magazine.find(ch);
      if (found == string::npos)
        return false;
      else
        magazine[found] = 'A';
    }
    return true;
  }
};

int main()
{
  Solution st;
  bool res = st.canConstruct("a", "b");
  cout << res << endl;

  return 0;
}