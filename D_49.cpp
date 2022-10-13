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
  int findKthPositive(vector<int> &arr, int k)
  {
    int start = 0, end = arr.size() - 1, mid;
    while (start <= end)
    {
      mid = start + ((end - start) / 2);
      if (arr[mid] - mid > k)
        end = mid - 1;
      else
        start = mid + 1;
    }
    return start + k;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {2, 3, 4, 7, 11};
  cout << st.findKthPositive(nums, 5) << endl;

  return 0;
}