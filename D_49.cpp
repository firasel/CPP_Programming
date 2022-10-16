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
};

int main()
{
  Solution st;
  vector<int> nums = {1, 13, 10, 12, 31};
  cout << st.countDistinctIntegers(nums) << endl;

  return 0;
}