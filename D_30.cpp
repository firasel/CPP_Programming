#include<bits/stdc++.h>
#include"D_30.h"

using namespace std;

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout<<st.size()<<endl;
    if(!st.empty()) cout<<st.Top()<<endl;

    while(!st.empty())
    {
        cout<<st.pop()<<" ";
    }

    cout<<endl;
    if(!st.empty()) cout<<st.Top()<<endl;

    return 0;
}

