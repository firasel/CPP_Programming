#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
  {
    map<int, int> numsMap;
    vector<int> result;
    for (auto num : nums1)
      numsMap[num]++;
    for (auto num : nums2)
      if (--numsMap[num] >= 0)
        result.push_back(num);
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