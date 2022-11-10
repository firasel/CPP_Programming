#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class Solution
{
public:
  string multiply(string num1, string num2)
  {
    if (num1 == "0" || num2 == "0")
      return "0";
    int len1 = num1.length(), len2 = num2.length();
    string ans(len1 + len2, '0');
    for (int i = len1 - 1; i >= 0; i--)
    {
      for (int j = len2 - 1; j >= 0; j--)
      {
        int res = (ans[i + j + 1] - '0') + ((num1[i] - '0') * (num2[j] - '0'));
        ans[i + j + 1] = res % 10 + '0';
        ans[i + j] += res / 10;
      }
    }
    if (ans[0] == '0')
      return ans.substr(1);
    return ans;
  }
};

int main()
{
  Solution st;
  string res = st.multiply("123", "456");
  cout << res << endl;
  return 0;
}