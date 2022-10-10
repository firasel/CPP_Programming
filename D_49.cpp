#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

class Solution
{
public:
  int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
  {
    int count = 0;
    for (auto num : arr1)
    {
      bool chk = true;
      for (auto num2 : arr2)
      {
        if (abs(num - num2) <= d)
        {
          chk = false;
          break;
        }
      }
      if (chk)
        count++;
    }
    return count;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {4, 5, 8};
  vector<int> nums2 = {10, 9, 1, 8};
  cout << st.findTheDistanceValue(nums, nums2, 2) << endl;

  return 0;
}