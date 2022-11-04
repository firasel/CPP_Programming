#include <bits/stdc++.h>
using namespace std;

int digit_sum(long long num)
{
  long long sum = 0;
  while (num > 0)
  {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

int main()
{
  long long n, s;
  cin >> n >> s;
  long long lo = 1, hi = n + 1;
  while (lo < hi)
  {
    long long mid = lo + (hi - lo) / 2;
    if (mid - digit_sum(mid) >= s)
      hi = mid;
    else
      lo = mid + 1;
  }
  if (lo > n)
    cout << 0 << endl;
  else
    cout << n - lo + 1 << endl;
  return 0;
}