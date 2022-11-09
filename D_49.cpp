#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class Solution
{
public:
  vector<int> partitionLabels(string s)
  {
    vector<int> ans;
    int start = 0, last = -1, pos;
    for (int i = 0; i < s.size(); i++)
    {
      pos = s.find_last_of(s[i]);
      if (pos > last)
        last = pos;
      if (last == i)
      {
        ans.push_back(last + 1 - start);
        last += 1;
        start = last;
      }
    }
    return ans;
  }
};

int main()
{
  Solution st;
  vector<int> res = st.partitionLabels("caedbdedda");
  for (auto num : res)
    cout << num << " ";
  cout << endl;

  return 0;
}