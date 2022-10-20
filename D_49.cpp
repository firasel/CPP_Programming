#include <iostream>
using namespace std;

void A(int n, int pos)
{
  cout << "sin(" << pos;
  if (pos < n)
  {
    if (pos & 1)
      cout << "-";
    else
      cout << "+";
    A(n, pos + 1);
  }
  cout << ")";
}

void S(int n, int pos)
{
  if (pos < n)
  {
    cout << "(";
    S(n, pos + 1);
    cout << ")";
  }
  A(n + 1 - pos, 1);
  cout << "+" << pos;
}

int main()
{
  int n;
  cin >> n;
  S(n, 1);
  return 0;
}