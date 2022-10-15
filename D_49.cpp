#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    for (auto nums : matrix)
    {
      int size = nums.size() - 1;
      if (nums[0] > target)
        return false;
      if (nums[size] >= target)
      {
        int start = 0, end = size, mid;
        while (start <= end)
        {
          mid = (start + end) / 2;
          if (nums[mid] == target)
            return true;
          else if (nums[mid] < target)
            start = mid + 1;
          else
            end = mid - 1;
        }
      }
    }
    return false;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> grid = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  cout << st.searchMatrix(grid, 3) << endl;

  return 0;
}