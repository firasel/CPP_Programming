#include <bits/stdc++.h>
#include <iostream>
#include <numeric>

using namespace std;

class Solution
{
public:
  vector<int> findDisappearedNumbers(vector<int> &nums)
  {
    vector<int> ans;
    if (nums.empty())
      return ans;
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
      while (nums[nums[i] - 1] != nums[i])
      {
        swap(nums[nums[i] - 1], nums[i]);
      }
    }

    for (int i = 0; i < n; ++i)
    {
      cout << nums[i] << " ";
      if (nums[i] != i + 1)
      {
        ans.push_back(i + 1);
      }
    }
    cout << endl;

    return ans;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
  vector<int> res = st.findDisappearedNumbers(nums);
  for (auto num : res)
    cout << num << " ";
  cout << endl;

  return 0;
}