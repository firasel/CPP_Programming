#include<bits/stdc++.h>
//#include"D_30.h"
//#include"MY_QUEUE.h"

using namespace std;

void insertElement(queue<int> &qu, int n)
{
    for(int i=0; i<n; i++)
    {
        int val;
        cin>>val;
        qu.push(val);
    }
}

void reverseQueue(queue <int> &qu)
{
    stack <int> st;
    while(!qu.empty())
    {
        st.push(qu.front());
        qu.pop();
    }
    while(!st.empty())
    {
        qu.push(st.top());
        st.pop();
    };
}

int main()
{
    queue <int> qu;
    int n;
    cin>>n;
    insertElement(qu, n);
    reverseQueue(qu);

    while(!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }
    cout<<endl;
    return 0;
}

