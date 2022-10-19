#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
public:
  vector<string> topKFrequent(vector<string> &words, int k)
  {
    vector<string> res;
    sort(words.begin(), words.end());
    map<string, int> freqMap;
    for (auto str : words)
      freqMap[str]++;
    multimap<int, string, greater<int>> freqSrtMap;

    for (auto el : freqMap)
      freqSrtMap.insert({el.second, el.first});
    int i = 0;
    for (auto el : freqSrtMap)
    {
      res.push_back(el.second);
      i++;
      if (i >= k)
        break;
    }
    return res;
  }
};

int main()
{
  Solution st;
  vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
  vector<string> res = st.topKFrequent(words, 2);
  for (auto str : res)
    cout << str << " ";
  cout << endl;
  return 0;
}