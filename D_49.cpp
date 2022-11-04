#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    map<int, int> mapNum = {{0, 0}, {1, 0}, {2, 0}};
    for (auto num : nums)
      mapNum[num]++;
    for (int i = 0; i < nums.size(); i++)
    {
      if (--mapNum[0] >= 0)
        nums[i] = 0;
      else if (--mapNum[1] >= 0)
        nums[i] = 1;
      else if (--mapNum[2] >= 0)
        nums[i] = 2;
    }
  }
};

int main()
{
  Solution st;
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  st.sortColors(nums);
  for (auto num : nums)
    cout << num << " ";
  cout << endl;
  return 0;
}