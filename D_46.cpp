#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> visited;
        int max = 0, count = 0;
        for (int i = 1; i <= s.length(); i++)
        {
            if (!visited[s[i - 1]])
            {
                visited[s[i - 1]] = i;
                count++;
            }
            else
            {
                if (max < count)
                {
                    max = count;
                }
                s = s.substr(visited[s[i - 1]]);
                i = 0;
                count = 0;
                visited.clear();
            }
        }
        if (max < count)
        {
            max = count;
        }

        return max;
    }
};

int main()
{
    Solution st;
    int res = st.lengthOfLongestSubstring(" ");
    cout << res << endl;
    return 0;
}
