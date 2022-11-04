#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());
    int size = intervals.size() - 1;
    for (int i = 0; i <= size; i++)
    {
      if (i == size)
        res.push_back(intervals[i]);
      else if (intervals[i][1] >= intervals[i + 1][0])
      {
        intervals[i + 1][0] = intervals[i][0];
        intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
      }
      else
        res.push_back({intervals[i][0], intervals[i][1]});
    }
    return res;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> nums = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<vector<int>> res = st.merge(nums);
  for (auto resNums : res)
  {
    for (auto num : resNums)
      cout << num << " ";
    cout << endl;
  }
  return 0;
}