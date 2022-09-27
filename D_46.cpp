#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int count = 0, last = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
            {
                while (true && last >= 0)
                {
                    if (val != nums[last])
                        break;
                    last--;
                }
                nums[i] = last > 0 ? nums[last] : 0;
                last--;
            }
            else
                count++;
        }
        return count;
    }
};

int main()
{
    Solution st;
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int res = st.removeElement(nums, 2);
    cout << res << endl;
    return 0;
}
