#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

class Solution
{
public:
  bool judgeSquareSum(int c)
  {
    long long int left = 0, right = sqrt(c);
    while (left <= right)
    {
      long long int total = left * left + right * right;
      if (total < c)
        left++;
      else if (total > c)
        right--;
      else
        return true;
    }
    return false;
  }
};

int main()
{
  Solution st;
  cout << st.judgeSquareSum(5) << endl;

  return 0;
}