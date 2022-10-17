#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

class Solution
{
public:
  bool checkIfPangram(string sentence)
  {
    unordered_map<char, int> alphabet;
    for (auto ch : sentence)
      alphabet[ch]++;
    return alphabet.size() == 26;
  }
};

int main()
{
  Solution st;
  cout << st.checkIfPangram("thequickbrownfoxjumpsoverthelazydog") << endl;

  return 0;
}