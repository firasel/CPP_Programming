#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int t, cnt = 1;
  cin >> t;
  while (t--)
  {
    int n, k, limit = 0;
    cin >> n >> k;
    string s = "";
    for (int i = 0; i < n; i++)
      s += 65 + i;
    cout << "Case " << cnt++ << ":" << endl;
    do
    {
      cout << s << endl;
      limit++;
    } while (next_permutation(s.begin(), s.end()) && limit < k);
  }
  return 0;
}