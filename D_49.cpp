#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class Solution
{
public:
  string sumOfSingleNum(int num1 = 0, int num2 = 0, int carr = 0)
  {
    return to_string((num1 + num2 + carr));
  }

  int strToNum(string numStr)
  {
    if (numStr.size() == 0)
      return 0;
    int num = 0;
    for (auto ch : numStr)
      num *= 10, num += (ch - '0');
    return num;
  }

  string addStrings(string num1, string num2)
  {
    string ans = "", temp;
    int carr = 0, n1 = num1.size() - 1, n2 = num2.size() - 1;
    while (n1 >= 0 && n2 >= 0)
    {
      temp = sumOfSingleNum(num1[n1] - '0', num2[n2] - '0', carr);
      ans = temp.back() + ans;
      temp.pop_back();
      carr = strToNum(temp);
      n1--;
      n2--;
    }

    while (n1 >= 0)
    {
      temp = sumOfSingleNum(num1[n1] - '0', 0, carr);
      ans = temp.back() + ans;
      temp.pop_back();
      carr = strToNum(temp);
      n1--;
    }

    while (n2 >= 0)
    {
      temp = sumOfSingleNum(num2[n2] - '0', 0, carr);
      ans = temp.back() + ans;
      temp.pop_back();
      carr = strToNum(temp);
      n2--;
    }

    if (carr > 0)
      ans = to_string(carr) + ans;
    return ans;
  }
};

int main()
{
  Solution st;
  string res = st.addStrings("3876620623801494171", "6529364523802684779");
  cout << res << endl;

  return 0;
}