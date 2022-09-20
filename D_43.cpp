#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <math.h>
using namespace std;

int steadyGene(string gene)
{
    map<char, int> uniCharMap;
    for (char c : gene)
        uniCharMap[c]++;
    int len = gene.size() / 4;
    if (uniCharMap['A'] <= len && uniCharMap['C'] <= len && uniCharMap['G'] <= len && uniCharMap['T'] <= len)
    {
        return 0;
    }
    int minNum = gene.size();
    int i = 0, j = 0;
    while (j < gene.size())
    {

        if (uniCharMap['A'] <= len && uniCharMap['C'] <= len && uniCharMap['G'] <= len && uniCharMap['T'] <= len)
        {
            uniCharMap[gene[i]]++;
            i++;
            minNum = min(minNum, (j - i + 1));
        }
        else
        {
            uniCharMap[gene[j]]--;
            j++;
        }
    }
    return minNum;
}

int main()
{
    int option;
    int selectNum;
    string currStr;
    stack<string> historySt;

    cin >> option;
    while (option > 0)
    {
        cin >> selectNum;
        if (selectNum == 1)
        {
            string addStr;
            cin >> addStr;
            historySt.push(currStr);
            currStr += addStr;
        }
        else if (selectNum == 2)
        {
            int l;
            cin >> l;
            historySt.push(currStr);
            currStr.erase(currStr.size() - l);
        }
        else if (selectNum == 3)
        {
            int k;
            cin >> k;
            cout << currStr[k - 1] << endl;
        }
        else
        {
            currStr = historySt.top();
            historySt.pop();
        }
        option--;
    }
    return 0;
}