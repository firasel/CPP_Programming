#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

class Solution
{
public:
  int countNegatives(vector<vector<int>> &grid)
  {
    int count = 0;
    for (auto nums : grid)
    {
      int size = nums.size() - 1;
      for (int i = size; i >= 0; i--)
        if (nums[i] < 0)
          count++;
    }
    return count;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> grid = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
  cout << st.countNegatives(grid) << endl;

  return 0;
}