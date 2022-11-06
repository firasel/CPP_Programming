#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals)
  {
    sort(intervals.begin(), intervals.end());
    int count = 0, prev = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++)
    {
      if (prev > intervals[i][0])
      {
        count++;
        prev = min(prev, intervals[i][1]);
      }
      else
        prev = intervals[i][1];
    }
    return count;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> intervals = {{1, 100}, {11, 22}, {1, 11}, {2, 12}};
  vector<vector<int>> intervals2 = {
      {-52, 31}, {-73, -26}, {82, 97}, {-65, -11}, {-62, -49}, {95, 99}, {58, 95}, {-31, 49}, {66, 98}, {-63, 2}, {30, 47}, {-40, -26}};
  int res = st.eraseOverlapIntervals(intervals);
  int res2 = st.eraseOverlapIntervals(intervals2);
  cout << res << endl;
  cout << res2 << endl;
  return 0;
}