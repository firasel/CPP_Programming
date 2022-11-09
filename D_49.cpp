#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class Solution
{
public:
  bool wordPattern(string pattern, string s)
  {
    unordered_map<char, string> chMp;
    unordered_map<string, char> wdMp;
    istringstream ss(s);
    string word;
    int i = 0;
    while (ss >> word)
    {
      if (chMp.find(pattern[i]) == chMp.end() && wdMp.find(word) == wdMp.end())
      {
        chMp[pattern[i]] = word;
        wdMp[word] = pattern[i];
      }
      else
      {
        if (chMp[pattern[i]] != word || wdMp[word] != pattern[i])
          return false;
      }
      i++;
    };
    return chMp.size() == wdMp.size() && i == pattern.size();
  }
};

int main()
{
  Solution st;
  bool res = st.wordPattern("abba", "dog cat cat dog");
  cout << res << endl;

  return 0;
}