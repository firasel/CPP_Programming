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
  int largestPerimeter(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    for (int i = size - 3; i >= 0; i--)
      if (nums[i] + nums[i + 1] > nums[i + 2])
        return nums[i] + nums[i + 1] + nums[i + 2];
    return 0;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {2, 1, 2};
  cout << st.largestPerimeter(nums) << endl;

  return 0;
}