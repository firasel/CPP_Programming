#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int count = 0;
        int i;
        for (i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                count++;
                if (count > 1)
                {
                    nums.erase(nums.begin() + i + 1);
                    i--;
                }
            }
            else
            {
                count = 0;
            }
        }
        return i + 1;
    }
};

int main()
{
    Solution st;
    vector<int> nums = {0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 3, 3, 3, 3};
    int res = st.removeDuplicates(nums);

    cout << res << endl;

    return 0;
}
