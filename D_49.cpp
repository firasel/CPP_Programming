#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> applyOperations(vector<int> &nums)
  {
    int size = nums.size(), index = 0;
    for (int i = 0; i < size - 1; i++)
    {
      if (nums[i] == nums[i + 1])
      {
        nums[i] *= 2;
        nums[i + 1] = 0;
      }
    }

    for (int i = 0; i < size; i++)
      if (nums[i] != 0)
        nums[index++] = nums[i];

    while (index < size)
      nums[index++] = 0;

    return nums;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {1, 2, 2, 1, 1, 0};
  vector<int> res = st.applyOperations(nums);
  for (auto num : res)
    cout << num << " ";
  cout << endl;
  return 0;
}