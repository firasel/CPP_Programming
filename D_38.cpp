#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &students, vector<int> &sandwiches)
{
    queue<int> st;
    queue<int> sw;
    for (int i : students)
        st.push(i);
    for (int i : sandwiches)
        sw.push(i);
    int count = 0;
    while (!st.empty() && count != st.size())
    {
        if (st.front() == sw.front())
        {
            st.pop();
            sw.pop();
            count = 0;
        }
        else
        {
            int frontSt = st.front();
            st.pop();
            st.push(frontSt);
            count++;
        }
    }
    return st.size();
}

int main()
{
    vector<int> st = {1, 1, 1, 0, 0, 1, 1};
    vector<int> sw = {1, 0, 0, 1};
    cout << countStudents(st, sw) << endl;
    return 0;
}
