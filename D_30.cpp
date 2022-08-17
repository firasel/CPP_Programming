#include<bits/stdc++.h>
#include"D_30.h"

using namespace std;

int main()
{
    Stack <pair<int, char>> st;
    st.push(make_pair(1,'a'));
    st.push(make_pair(2,'b'));
    st.push(make_pair(3,'c'));
    st.push(make_pair(4,'d'));

    cout<<st.size()<<endl;
    while(!st.empty())
    {
        pair<int, char> chk;
        chk = st.pop();
        cout<<chk.first<<" | "<<chk.second<<endl;
    }

    return 0;
}

