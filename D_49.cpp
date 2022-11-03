#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    int ans = nums[nums.size() - 1];
    int count = 1;
    for (int i = 0; i < nums.size() - 1; i++)
    {
      if (nums[i] == nums[i + 1])
      {
        count++;
      }
      else
      {
        if (count > nums.size() / 2)
          ans = nums[i];
        count = 0;
      }
    }
    return ans;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {-1, 1, 1, 1, 2, 1};
  cout << st.majorityElement(nums) << endl;
  return 0;
}