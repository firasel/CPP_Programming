#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> res;
    for (int i = 0; i < strs.size(); i++)
    {
      string temp = strs[i];
      sort(temp.begin(), temp.end());
      res[temp].push_back(strs[i]);
    }
    for (auto strVect : res)
      ans.push_back(strVect.second);
    return ans;
  }
};

int main()
{
  Solution st;
  vector<string> strs = {"", "", ""};
  vector<vector<string>> res = st.groupAnagrams(strs);
  for (auto strs : res)
  {
    for (auto w : strs)
      cout << w << " ";
    cout << endl;
  }
  cout << endl;

  return 0;
}