#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> nums1(n);
  vector<int> nums2(m);
  for (int i = 0; i < n; i++)
    cin >> nums1[i];
  for (int i = 0; i < m; i++)
    cin >> nums2[i];
  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());
  int count = 0;
  if (nums1[0] < nums2[m - 1])
  {
    int conNum = nums2[(m - 1) / 2];
    for (int i = 0; i < n; i++)
      count += abs(nums1[i] - conNum);
    for (int i = 0; i < m; i++)
      count += abs(nums2[i] - conNum);
  }
  cout << count << endl;
  return 0;
}