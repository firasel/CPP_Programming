#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

int testNum = 4;
bool isBadVersion(int version)
{
  return version == testNum;
}

class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int target)
  {
    vector<int> result = {-1, -1};
    int start = 0, end = nums.size() - 1, mid;
    while (start <= end)
    {
      mid = start + ((end - start) / 2);
      if (nums[mid] == target)
      {
        result[0] = mid;
        end = mid - 1;
      }
      else if (nums[mid] > target)
        end = mid - 1;
      else
        start = mid + 1;
    }

    start = 0, end = nums.size() - 1;
    while (start <= end)
    {
      mid = start + ((end - start) / 2);
      if (nums[mid] == target)
      {
        result[1] = mid;
        start = mid + 1;
      }
      else if (nums[mid] > target)
        end = mid - 1;
      else
        start = mid + 1;
    }
    return result;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {5, 7, 7, 8, 8, 10};
  vector<int> result = st.searchRange(nums, 8);
  cout << result[0] << " " << result[1] << endl;

  return 0;
}