#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

class Solution
{
public:
  int maxDistance(vector<int> &nums1, vector<int> &nums2)
  {
    int res = 0, len1 = nums1.size(), len2 = nums2.size();
    for (int i = 0; i < len1; i++)
    {
      int start = i, end = len2 - 1, mid;
      while (start <= end)
      {
        mid = (start + end) / 2;
        if (nums1[i] > nums2[mid])
          end = mid - 1;
        else if (nums1[i] <= nums2[mid])
        {
          if (mid + 1 != len2 && nums1[i] > nums2[mid + 1])
            break;
          else
            start = mid + 1;
        }
      }
      if (res < mid - i)
        res = mid - i;
    }
    return res;
  }
};

int main()
{
  Solution st;
  vector<int> nums1 = {55, 30, 5, 4, 2};
  vector<int> nums2 = {100, 20, 10, 10, 5};
  cout << st.maxDistance(nums1, nums2) << endl;

  return 0;
}