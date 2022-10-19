#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int t, n, c;
  cin >> t;
  while (t--)
  {
    cin >> n >> c;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];
    sort(nums.begin(), nums.end());
    int start = 0, end = nums[n - 1], mid, res = 0;
    while (start <= end)
    {
      mid = (start + end) / 2;
      int cCount = 1, prev = 0;
      for (int i = 1; i < n && cCount < c; i++)
      {
        if (nums[i] - nums[prev] >= mid)
          prev = i, cCount++;
      }
      if (cCount >= c)
      {
        res = mid;
        start = mid + 1;
      }
      else
        end = mid - 1;
    }
    cout << res << endl;
  }
  return 0;
}