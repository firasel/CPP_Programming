#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    int size = nums.size(), prev = 1, curr = 1;
    vector<int> res(size, 0);
    int total = accumulate(nums.begin(), nums.end(), 1, multiplies<int>());
    for (int i = 0; i < size; i++)
    {
      res[i] = prev;
      prev *= nums[i];
    }
    prev = 1;
    for (int i = size - 1; i >= 0; i--)
    {
      curr = prev * nums[i];
      nums[i] = prev;
      prev = curr;
    }

    for (int i = 0; i < size; i++)
      res[i] *= nums[i];
    return res;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {1, 2, 3, 4};
  vector<int> res = st.productExceptSelf(nums);
  for (auto num : res)
    cout << num << " ";
  cout << endl;

  return 0;
}