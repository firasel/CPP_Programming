#include <math.h>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void sqrtOfNUm(vector<long long> &nums, int index, int size)
{
  if (index >= size)
    return;
  sqrtOfNUm(nums, index + 1, size);
  cout << fixed << setprecision(4) << sqrt(nums[index]) << endl;
}

int main()
{
  long long num;
  vector<long long> nums;
  while (cin >> num)
    nums.push_back(num);
  sqrtOfNUm(nums, 0, nums.size());
  return 0;
}