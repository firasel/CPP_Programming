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
  int arrangeCoins(int n)
  {
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
      if (i <= n)
        count++;
      n -= i;
    }
    return count;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {2, 1, 2};
  cout << st.arrangeCoins(5) << endl;

  return 0;
}