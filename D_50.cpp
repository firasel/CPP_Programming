#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  while (n--)
  {
    int l, r, max = 0, num;
    cin >> l >> r;

    for (int i = l; i <= r; i++)
    {
      int cnt = 0, lim = sqrt(i);
      for (int j = 1; j <= lim; j++)
      {
        if (j * j == i)
          cnt++;
        else if (i % j == 0)
          cnt += 2;
      }
      if (max < cnt)
      {
        max = cnt;
        num = i;
      }
    }
    cout << "Between " << l << " and " << r << ", " << num << " has a maximum of " << max << " divisors." << endl;
  }
  return 0;
}