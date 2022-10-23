#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int strToInt(string str, int curr)
  {
    if (str[0] >= '0' && str[0] <= '9')
      curr = curr * 10 + (str[0] - '0');
    if (str.length() >= 1)
      return strToInt(str.substr(1), curr);
    return curr;
  }

  bool haveConflict(vector<string> &event1, vector<string> &event2)
  {
    int ev1st = strToInt(event1[0], 0), ev1end = strToInt(event1[1], 0), ev2st = strToInt(event2[0], 0), ev2end = strToInt(event2[1], 0);
    if (ev1st > ev2st && ev1st > ev2end)
      return false;
    else if (ev1end >= ev2st)
      return true;
    return false;
  }
};

int main()
{
  Solution st;
  vector<string> nums1 = {"10:13", "13:02"};
  vector<string> nums2 = {"13:17", "21:38"};
  bool res = st.haveConflict(nums1, nums2);
  cout << res << endl;
  return 0;
}