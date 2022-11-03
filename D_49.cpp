#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    int ans = nums[0];
    for (int i = 0; i < nums.size(); i += 2)
    {
      if (nums[i] != nums[i + 1])
      {
        ans = nums[i];
        break;
      }
    }
    return ans;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {4, 1, 4, 1, 2};
  cout << st.singleNumber(nums) << endl;
  return 0;
}