#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, q, pos = -1;
  cin >> n;
  vector<int> nums;
  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    if (nums.size() == 0 || nums[pos] != num)
    {
      nums.push_back(num);
      pos++;
    }
  }
  cin >> q;
  while (q--)
  {
    int num;
    cin >> num;
    int sl = 0, tl = INT32_MAX;
    for (auto el : nums)
    {
      if (el < num && el > sl)
        sl = el;
      if (el > num && el < tl)
        tl = el;
    }
    if (sl == 0)
      cout << "X ";
    else
      cout << sl << " ";
    if (tl == INT32_MAX)
      cout << "X" << endl;
    else
      cout << tl << endl;
  }
  return 0;
}