#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

class Solution
{
public:
  int hardestWorker(int n, vector<vector<int>> &logs)
  {
    int id;
    int max = 0, prev = 0, size = logs.size();
    for (int i = 0; i < size; i++)
    {
      if (max < (logs[i][1] - prev))
      {
        max = logs[i][1] - prev;
        id = logs[i][0];
      }
      else if (max == (logs[i][1] - prev))
        id = min(id, logs[i][0]);
      prev = logs[i][1];
    }
    return id;
  }
};

int main()
{
  Solution st;
  vector<vector<int>> logs = {{0, 3}, {2, 5}, {0, 9}, {1, 15}};
  cout << st.hardestWorker(10, logs) << endl;

  return 0;
}