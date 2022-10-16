#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

class Solution
{
public:
  int findMaxK(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    int size = nums.size() - 1;
    for (int i = size; i >= 0; i--)
    {
      if (nums[i] < 0)
        break;
      else
      {
        int start = 0, end = size, target = nums[i] * -1;
        while (start <= end)
        {
          int mid = (start + end) / 2;
          if (nums[mid] == target)
            return target * -1;
          else if (nums[mid] < target)
            start = mid + 1;
          else
            end = mid - 1;
        }
      }
    }
    return -1;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {-1, 10, 6, 7, -7, 1};
  cout << st.findMaxK(nums) << endl;

  return 0;
}