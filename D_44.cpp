#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int array[n];

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    map<int, int> M;

    for (int i = 0; i < n; i++)
    {
        M[array[i]]++;
    }

    map<int, int>::iterator it;
    for (it = M.begin(); it != M.end(); it++)
    {
        cout << it->first << " = " << it->second << endl;
    }

    int result[n];
    int j = 0;
    it = M.begin();
    while (it != M.end())
    {
        if (it->second > 0)
        {
            result[j] = it->first;
            M[it->first]--;
            j++;
        }
        else
        {
            it++;
        }
    }

    cout << endl
         << endl
         << "Sorted Array: ";
    for (auto i : result)
        cout << i << " ";
    cout << endl;

    return 0;
}
