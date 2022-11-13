#include <math.h>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void sqrtOfNUm(vector<long long> &nums, int size)
{
  if (size >= 0)
    return;
  cout << fixed << setprecision(4) << sqrt(nums[size--]) << endl;
  sqrtOfNUm(nums, size);
}

int main()
{
  long long num;
  vector<long long> nums;
  while (cin >> num)
    nums.push_back(num);
  sqrtOfNUm(nums, nums.size() - 1);
  return 0;
}