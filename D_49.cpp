#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
  int n, d, r;
  while (cin >> n >> d >> r && (n || d || r))
  {
    int sum = 0;
    vector<int> m(n);
    vector<int> e(n);
    for (int i = 0; i < n; i++)
      cin >> m[i];
    for (int i = 0; i < n; i++)
      cin >> e[i];
    sort(m.begin(), m.end());
    sort(e.begin(), e.end(), greater<int>());
    for (int i = 0; i < n; i++)
      if (m[i] + e[i] > d)
        sum += (m[i] + e[i]) - d;
    cout << sum * r << endl;
  }
  return 0;
}