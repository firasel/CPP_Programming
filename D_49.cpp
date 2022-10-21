#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    int size = nums.size();
    for (int i = 0; i < size - 1; i++)
    {
      for (int j = i + 1; j < size; j++)
        if (nums[i] + nums[j] == target)
          return {i, j};
    }
    return {-1, -1};
  }
};

int main()
{
  Solution st;
  vector<int> nums = {2, 7, 11, 15};
  vector<int> res = st.twoSum(nums, 9);
  cout << res[0] << " " << res[1] << endl;
  return 0;
}