#include <bits/stdc++.h>
#include <iostream>
#include <numeric>

using namespace std;

class Solution
{
public:
  int findTheWinner(int n, int k)
  {
    int cnt = 1, temp;
    queue<int> nums;
    for (int i = 1; i <= n; i++)
      nums.push(i);
    while (nums.size() > 1)
    {
      temp = nums.front();
      nums.pop();
      if (cnt == k)
        cnt = 0;
      else
        nums.push(temp);
      cnt++;
    }
    return nums.front();
  }
};

int main()
{
  Solution st;
  int res = st.findTheWinner(5, 2);
  cout << res << endl;
  return 0;
}