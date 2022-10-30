#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

string colorMixing(string s)
{
    string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != s[i + 1])
        {
            if ((s[i] == 'R' && s[i + 1] == 'B') || (s[i] == 'B' && s[i + 1] == 'R'))
            {
                result += 'P';
                i++;
            }
            else if ((s[i] == 'R' && s[i + 1] == 'G') || (s[i] == 'G' && s[i + 1] == 'R'))
            {
                result += 'Y';
                i++;
            }
            else if ((s[i] == 'B' && s[i + 1] == 'G') || (s[i] == 'G' && s[i + 1] == 'B'))
            {
                result += 'C';
                i++;
            }
            else if (s[i] != s[i + 1])
            {
                result.push_back(s[i]);
            }
        }
        else
            i++;
    }
    return result;
}

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string prev = s, final = s;
        do
        {
            prev = final;
            final = colorMixing(prev);
        } while (prev != final);
        cout << final << endl;
        t--;
    }
    return 0;
}