#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    for (auto num : nums2)
      nums1[m++] = num;
    sort(nums1.begin(), nums1.end());
  }
};

int main()
{
  Solution st;
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};
  int m = 3, n = 3;
  st.merge(nums1, m, nums2, n);
  for (auto num : nums1)
    cout << num << " ";
  cout << endl;

  return 0;
}