#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void rotate(vector<vector<int>> &matrix)
  {
    reverse(matrix.begin(), matrix.end());
    int size = matrix.size();
    for (int j = 0; j < size; j++)
    {
      for (int i = j + 1; i < size; i++)
      {
        int temp = matrix[j][i];
        matrix[j][i] = matrix[i][j];
        matrix[i][j] = temp;
      }
    }
  }
};

int main()
{
  Solution st;
  vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  st.rotate(matrix);
  for (auto nums : matrix)
  {
    for (auto num : nums)
      cout << num << " ";
    cout << endl;
  }
  cout << endl;
  return 0;
}