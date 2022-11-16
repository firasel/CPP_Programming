#include <iostream>
#include <vector>
using namespace std;

int findMinDif(vector<int> &nums, int n, int sum, int totalSum)
{
  if (n == 0)
    return abs((totalSum - sum) - sum);
  return min(findMinDif(nums, n - 1, sum + nums[n - 1], totalSum), findMinDif(nums, n - 1, sum, totalSum));
}

int main()
{
  int n, sum = 0;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
    sum += nums[i];
  }
  cout << findMinDif(nums, n, 0, sum) << endl;
  return 0;
}