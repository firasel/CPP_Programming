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
  vector<int> twoSum(vector<int> &numbers, int target)
  {
    int start = 0, end = numbers.size() - 1;
    while (start < end)
    {
      if (numbers[start] + numbers[end] == target)
        return {start + 1, end + 1};
      else if (numbers[start] + numbers[end] > target)
        end--;
      else
        start++;
    }
    return {0, 0};
  }
};

int main()
{
  Solution st;
  vector<int> nums = {2, 7, 11, 15};
  vector<int> res = st.twoSum(nums, 9);
  for (auto num : res)
    cout << num << " ";
  cout << endl;

  return 0;
}