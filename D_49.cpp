#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

class Solution
{
public:
  int searchInsert(vector<int> &nums, int target)
  {
    int start = 0, end = nums.size() - 1;
    if (nums.size() == 0)
      return start;
    while (start <= end)
    {
      int mid = (start + end) / 2;
      if (nums[mid] > target)
      {
        end = mid - 1;
      }
      else if (nums[mid] < target)
      {
        start = mid + 1;
      }
      else if (nums[mid] == target)
      {
        return mid;
      }
    }

    return start;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {1, 3, 5, 6};
  cout << st.searchInsert(nums, 7) << endl;

  return 0;
}