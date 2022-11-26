#include <iostream>
using namespace std;

int countGoal(string &s)
{
  int cnt = 0, size = s.length();
  for (int i = 0; i < size; i++)
    if (s[i] == '1')
      cnt++;
  return cnt;
}

int main()
{
  int a, b;
  cin >> a >> b;
  while (a == b)
  {
    string s1, s2;
    cin >> s1 >> s2;
    a = countGoal(s1);
    b = countGoal(s2);
  }
  if (a > b)
    cout << "Argentina" << endl;
  else
    cout << "Brazil" << endl;
  return 0;
}