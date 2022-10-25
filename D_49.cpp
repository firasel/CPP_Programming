#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
  }
};

int main()
{
  Solution st;
  bool res = st.isAnagram("anagram", "nagaram");
  cout << res << endl;

  return 0;
}