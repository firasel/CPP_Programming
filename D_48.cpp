#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> decompressRLElist(vector<int> &nums)
  {
    vector<int> result;
    for (int i = 0; i < nums.size(); i += 2)
    {
      for (int j = 0; j < nums[i]; j++)
        result.push_back(nums[i + 1]);
    }
    return result;
  }
};

int main()
{
  Solution st;
  vector<int> nums = {1, 1, 2, 3, 3, 4};
  vector<int> result = st.decompressRLElist(nums);
  for (auto i : result)
    cout << i << " ";
  cout << endl;
  return 0;
}
