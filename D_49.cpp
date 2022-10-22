#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int max = INT_MIN, min = INT_MAX, res = 0;
    for (auto num : prices)
    {
      if (num > max)
        max = num;
      if (num < min)
        min = num, max = num;
      if (max - min > res)
        res = max - min;
    }
    if (max - min > res)
      res = max - min;
    return res;
  }
};

int main()
{
  Solution st;
  vector<int> nums1 = {7, 1, 5, 3, 6, 4};
  int res = st.maxProfit(nums1);
  cout << res << endl;
  return 0;
}