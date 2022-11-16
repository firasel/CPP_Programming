#include <iostream>
#include <algorithm>
using namespace std;

void calcPalindrome(long long num, int it = 1)
{
  if (it == 1000)
    return;
  long long num2, sum;
  string s1, s2;
  s1 = to_string(num);
  reverse(s1.begin(), s1.end());
  num2 = stoi(s1);
  sum = num + num2;
  s1 = to_string(sum);
  s2 = s1;
  reverse(s2.begin(), s2.end());
  if (s1 == s2)
  {
    cout << it << " " << sum << endl;
    return;
  }
  if (sum < UINT32_MAX)
    calcPalindrome(sum, it += 1);
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    long long num;
    cin >> num;
    calcPalindrome(num);
  }
  return 0;
}