#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[k] != nums[i])
            {
                nums[k + 1] = nums[i];
                k++;
            }
        }
        return k + 1;
    }
};

int main()
{
    Solution st;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 7, 7, 7};
    cout << st.removeDuplicates(nums) << endl;
    return 0;
}
