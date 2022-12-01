#include <iostream>
using namespace std;

int main()
{
  int t, cnt = 1;
  cin >> t;
  while (t--)
  {
    string a;
    int b, j = 0;
    cin >> a >> b;
    long long r = 0;
    if (a[0] == '-')
      j = 1;
    if (b < 0)
      b = abs(b);
    while (j < a.size())
    {
      cout << "R: " << r;
      r = r * 10 + (a[j] - '0');
      cout << " " << r << " ";
      r %= b;
      cout << r << endl;
      j++;
    }

    if (r == 0)
      cout << "Case " << cnt++ << ": divisible" << endl;
    else
      cout << "Case " << cnt++ << ": not divisible" << endl;
  }
  return 0;
}