#include<bits/stdc++.h>

using namespace std;

int main()
{
    stack <int> st;
    queue <int> qu;
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        int val;
        cin>>val;
        qu.push(val);
    };

    for(int i=0; i<n/k; i++)
    {
        for(int j=0; j<k; j++)
        {
            st.push(qu.front());
            qu.pop();
        }
        while(!st.empty())
        {
            qu.push(st.top());
            st.pop();
        }
    }

    for(int j=0; j<n%k; j++)
    {
        st.push(qu.front());
        qu.pop();
    }

    while(!st.empty())
    {
        qu.push(st.top());
        st.pop();
    }

    while(!qu.empty())
    {
        cout<<qu.front()<<" ";
        qu.pop();
    }
    cout<<endl;

    return 0;
}

