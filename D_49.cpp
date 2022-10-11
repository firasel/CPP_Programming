#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

class Solution
{
public:
  int mySqrt(int x)
  {
    if (x < 2)
      return x;
    int start = 0, end = x, mid;
    while (start < end)
    {
      int mid = (start + end) / 2;
      if ((x / mid) >= mid)
        start = mid + 1;
      else
        end = mid;
    }
    return end - 1;
  }
};

int main()
{
  Solution st;
  cout << st.mySqrt(16) << endl;

  return 0;
}