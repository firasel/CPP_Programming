#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class Solution
{
public:
  string longestPalindrome(string s)
  {
    int ans_len = 0, size = s.size(), left, right;
    string ans = "";
    for (int i = 0; i < size; i++)
    {
      left = right = i;
      while (left >= 0 && right < size && s[left] == s[right])
      {
        if (right - left + 1 > ans_len)
        {
          ans = s.substr(left, right - left + 1);
          ans_len = right - left + 1;
        }
        left--;
        right++;
      }

      left = i;
      right = i + 1;
      while (left >= 0 && right < size && s[left] == s[right])
      {
        if (right - left + 1 > ans_len)
        {
          ans = s.substr(left, right - left + 1);
          ans_len = right - left + 1;
        }
        left--;
        right++;
      }
    }
    return ans;
  }
};

int main()
{
  Solution st;
  string res = st.longestPalindrome("cbbd");
  cout << res << endl;
  return 0;
}