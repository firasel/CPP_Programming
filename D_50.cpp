#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n;
  cin >> n;
  while (n--)
  {
    string str, s;
    cin >> str;
    for (int i = 0; i < 20; i++)
      s += "Yes";
    if (s.find(str, 0) == string::npos)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }

  return 0;
}