#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int finalValueAfterOperations(vector<string> &operations)
  {
    int res = 0;
    for (auto str : operations)
    {
      if (str == "++X" || str == "X++")
        res++;
      else
        res--;
    }
    return res;
  }
};

int main()
{
  Solution st;
  vector<string> operations = {"X++", "++X", "--X", "X--"};
  int res = st.finalValueAfterOperations(operations);
  cout << res << endl;

  return 0;
}