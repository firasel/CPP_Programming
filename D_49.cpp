#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class Solution
{
public:
  vector<string> findRepeatedDnaSequences(string s)
  {
    vector<string> res;
    if (s.size() < 10)
      return res;
    unordered_map<string, int> mp;
    for (int i = 0; i + 9 < s.size(); i++)
      mp[s.substr(i, 10)]++;
    for (auto subStr : mp)
      if (subStr.second > 1)
        res.push_back(subStr.first);
    return res;
  }
};

int main()
{
  Solution st;
  vector<string> res = st.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
  for (auto str : res)
    cout << str << endl;
  return 0;
}