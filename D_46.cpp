#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int uniNum;
        bool chk = false;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
                i++;
            else
            {
                uniNum = nums[i];
                chk = true;
            }
        }
        if (!chk && nums.size() % 2 == 1)
            uniNum = nums[nums.size() - 1];
        return uniNum;
    }
};

int main()
{
    Solution st;
    vector<int> nums = {1, 0, 1};
    cout << st.singleNumber(nums) << endl;
    return 0;
}
