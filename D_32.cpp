#include<bits/stdc++.h>
#include"MY_STACK.h"

using namespace std;

int main()
{
    int n, val;
    cin>>n;
    Stack<int> st;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        st.push(val);
    }

    cout<<"Mid: "<<st.mid()<<endl;

    while(!st.Empty()) cout<<st.pop()<<" ";

    return 0;
}

