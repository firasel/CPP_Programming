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
  int specialArray(vector<int> &nums)
  {
    for (int i = 0; i < 1001; i++)
    {
      int count = 0;
      for (auto num : nums)
        if (num >= i)
          count++;
      if (count == i)
        return count;
    }
    return -1;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {0, 4, 3, 0, 4};
  cout << st.specialArray(nums) << endl;

  return 0;
}