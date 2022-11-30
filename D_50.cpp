#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int k, prev;
  cin >> k;
  vector<int> primeNums = {2, 3};
  prev = primeNums.back();
  while (k--)
  {
    int n;
    cin >> n;
    while (primeNums.size() < n)
    {
      int num = prev + 2, flag = 1;
      for (int i = 2; i <= num / 2; i++)
      {
        if (num % i == 0)
        {
          flag = 0;
          break;
        }
      }
      if (flag)
      {
        primeNums.push_back(num);
        prev = num;
      }
      else
        prev += 2;
    }
    cout << primeNums[n - 1] << endl;
  }
  return 0;
}