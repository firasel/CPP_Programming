#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

class Solution
{
public:
  char nextGreatestLetter(vector<char> &letters, char target)
  {
    for (auto ch : letters)
      if (ch > target)
        return ch;
    return letters[0];
  }
};

int main()
{
  Solution st;
  vector<char> chars = {'c', 'f', 'j'};
  cout << st.nextGreatestLetter(chars, 'a') << endl;

  return 0;
}