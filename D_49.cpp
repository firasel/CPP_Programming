#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    int cnt = 0, sum = 0;
    unordered_map<int, int> trackMp;
    trackMp[0] = 1;
    for (int i = 0; i < nums.size(); i++)
    {
      sum += nums[i];
      if (trackMp.find(sum - k) != trackMp.end())
      {
        cnt += trackMp[sum - k];
      }
      trackMp[sum]++;
    }
    return cnt;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 1, 23, 21, 3, 1, 2, 1, 1, 1, 1, 1, 12, 2, 3, 2, 3, 2, 2};
  int res = st.subarraySum(nums, 22);
  cout << res << endl;

  return 0;
}