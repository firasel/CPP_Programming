#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

class Solution
{
public:
  bool isPerfectSquare(int num)
  {
    if (num < 2)
      return true;
    int temp = num / 2;
    for (long long int i = 0; i <= temp; i++)
    {
      if ((i * i) == num)
        return true;
      else if ((i * i) > num)
        return false;
    }
    return false;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {0, 1, 2, 3, 3, 3, 4, 2, 1, 0, 0};
  cout << st.isPerfectSquare(16) << endl;

  return 0;
}