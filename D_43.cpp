#include <bits/stdc++.h>
#include <map>

using namespace std;

string addBinary(string a, string b)
{
    string result = "";
    int i = a.size() - 1, j = b.size() - 1;
    int car = 0;

    while (true)
    {
        if (i < 0 && j < 0)
        {
            break;
        }
        int sum = ((i == -1 ? 0 : (a[i] - '0')) + (j == -1 ? 0 : (b[j] - '0')) + car);
        if (sum == 1)
        {
            result = '1' + result;
            car = 0;
        }
        else if (sum == 0)
        {
            result = '0' + result;
        }
        else if (sum > 1)
        {
            result = '0' + result;
            car = 1;
        }

        if (i >= 0)
            i--;
        if (j >= 0)
            j--;
    }

    cout << car;
    if (car == 1)
        result = '1' + result;

    return result;
}

int main()
{

    int n, e, l;
    cin >> n >> e;
    map<int, vector<int>> levelShop;
    levelShop[0].push_back(0);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        int level = a;
        for (auto shops : levelShop)
            for (int shop : shops.second)
                if (shop == a)
                    level = shops.first;
        levelShop[level + 1].push_back(b);
    }

    for (auto shops : levelShop)
    {
        cout << "Key " << shops.first << " : ";
        for (int shop : shops.second)
            cout << shop << " ";
        cout << endl;
    }
    cin >> l;
    for (int shop : levelShop[l])
        cout << shop << " ";

    return 0;
}