#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int lo, hi, mid;
    for (int i = 0; i < matrix.size(); i++)
    {
      if (matrix[i].front() <= target && matrix[i].back() >= target)
      {
        lo = 0, hi = matrix[i].size() - 1;
        while (lo <= hi)
        {
          mid = lo + (hi - lo) / 2;
          if (matrix[i][mid] == target)
            return true;
          else if (matrix[i][mid] > target)
            hi = mid - 1;
          else
            lo = mid + 1;
        }
      }
      if (matrix[i].front() > target)
        return false;
    }
    return false;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
  bool res = st.searchMatrix(matrix, 5);
  cout << res << endl;
  return 0;
}