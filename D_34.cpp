#include<bits/stdc++.h>
#include"D_30.h"

using namespace std;

int main()
{
    Stack <int> st;
    Stack <int> minSt;
    int n, min=INT_MAX;
    cin>>n;
    int array[n];
    for(int i=0; i<n; i++) cin>>array[i];

    for(int i=0; i<n; i++)
    {
        if(array[i]<=min)
        {
            minSt.push(array[i]);
            min=array[i];
        }
        st.push(array[i]);
    }

    while(!st.empty())
    {
        if(minSt.Top()!=st.Top())
        {
            st.pop();
            cout<<minSt.Top()<<" ";
        }
        else
        {
            cout<<minSt.Top()<<" ";
            minSt.pop();
            st.pop();
        }
    }
    cout<<endl;

    return 0;
}

