#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    int start = 0, end = nums.size() - 1;
    while (start <= end)
    {
      if (nums[start] == target)
        return start;
      else if (nums[end] == target)
        return end;
      start++;
      end--;
    }
    return -1;
  }
};

int main()
{
  Solution st;
  vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
  cout << st.search(nums1, 3) << endl;

  return 0;
}