#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    set<vector<int>> res;
    int size = nums.size(), sum, st, end;
    for (int i = 0; i < size - 2; i++)
    {
      st = i + 1, end = size - 1;
      while (st < end)
      {
        sum = nums[i] + nums[st] + nums[end];
        if (sum > 0)
          end--;
        else if (sum < 0)
          st++;
        else
        {
          vector<int> temp = {nums[i], nums[st], nums[end]};
          res.insert(temp);
          while (st < end && nums[st] == temp[1])
            st++;
          while (st < end && nums[end] == temp[2])
            end--;
        }
      }
    }

    vector<vector<int>> ans;
    for (auto nums : res)
      ans.push_back(nums);
    return ans;
  }
};

int main()
{
  Solution st;
  vector<int> tNums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> res = st.threeSum(tNums);
  for (auto nums : res)
  {
    for (auto num : nums)
      cout << num << " ";
    cout << endl;
  }
  return 0;
}