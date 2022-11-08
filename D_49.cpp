#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class Solution
{
public:
  int longestPalindrome(string s)
  {
    int cnt = 0, temp = 0, size = s.size();
    if (size < 1)
      return cnt;
    else if (size < 2)
      return 1;
    sort(s.begin(), s.end());
    for (int i = 0; i < size; i++)
    {
      if (i != size - 1 && s[i] == s[i + 1])
        i++, cnt += 2;
      else if (temp == 0)
        temp = 1;
    }
    return cnt + temp;
  }
};

int main()
{
  Solution st;
  int res = st.longestPalindrome("abccccdd");
  cout << res << endl;

  return 0;
}