#include <iostream>
using namespace std;

int f91(int num)
{
  int res = num;
  if (num < 101)
    res = f91(f91(num + 11));
  else
    res = num - 10;
  return res;
}

int main()
{
  int num;
  while (cin >> num && num)
    cout << "f91(" << num << ") = " << f91(num) << endl;
  return 0;
}