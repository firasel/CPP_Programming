#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

class Solution
{
public:
  int countDistinctIntegers(vector<int> &nums)
  {
    map<int, int> numCount;
    for (auto num : nums)
    {
      int revNum = 0, prevNum = num;
      while (num > 0)
      {
        revNum = (revNum * 10) + (num % 10);
        num /= 10;
      }
      numCount[revNum] = 1;
      numCount[prevNum] = 1;
    }
    return numCount.size();
  }
  bool sumOfNumberAndReverse(int num)
  {
    int i = num / 2;
    for (i; i <= num; i++)
    {
      int revNum = 0, currNum = i;
      while (currNum > 0)
      {
        revNum = (revNum * 10) + (currNum % 10);
        currNum /= 10;
      }
      if (revNum + i == num)
        return true;
    }
    return false;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {1, 13, 10, 12, 31};
  cout << st.sumOfNumberAndReverse(181) << endl;

  return 0;
}