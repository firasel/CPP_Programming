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
  int firstBadVersion(int n)
  {
    int start = 0, end = n, mid;
    while (true)
    {
      mid = start + ((end - start) / 2);
      if (isBadVersion(mid))
      {
        if (mid > 0 && isBadVersion(mid - 1))
          end = mid - 1;
        else
          return mid;
      }
      else
        start = mid + 1;
    }
    return mid;
  }
};

int main()
{
  Solution st;
  cout << st.firstBadVersion(5) << endl;

  return 0;
}