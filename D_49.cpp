#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

class Solution
{
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
  {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> result;
    if (nums1.size() < nums2.size())
    {
      for (auto num : nums1)
      {
        int size = nums2.size();
        for (int i = 0; i < size; i++)
        {
          if (num < nums2[i])
            break;
          if (num == nums2[i])
          {
            result.push_back(num);
            nums2[i] = -1;
            break;
          }
        }
      }
    }
    else
    {
      for (auto num : nums2)
      {
        int size = nums1.size();
        for (int i = 0; i < size; i++)
        {
          if (num < nums1[i])
            break;
          if (num == nums1[i])
          {
            result.push_back(num);
            nums1[i] = -1;
            break;
          }
        }
      }
    }
    return result;
  }
};

int main()
{
  Solution st;
  vector<int> nums1 = {1, 2, 2, 1};
  vector<int> nums2 = {2, 2};
  vector<int> res = st.intersect(nums1, nums2);
  for (auto num : res)
    cout << num << " ";
  cout << endl;

  return 0;
}