#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

class Solution
{
public:
  int peakIndexInMountainArray(vector<int> &arr)
  {
    int start = 0, end = arr.size() - 1;
    while (start <= end)
    {
      int mid = (start + end) / 2;
      if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        return mid;
      else if (arr[mid] < arr[mid - 1])
        end = mid - 1;
      else
        start = mid + 1;
    }
    return start;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {0, 1, 2, 3, 3, 3, 4, 2, 1, 0, 0};
  cout << st.peakIndexInMountainArray(nums) << endl;

  return 0;
}