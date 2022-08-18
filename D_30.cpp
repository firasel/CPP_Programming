#include<bits/stdc++.h>
#include"D_30.h"

using namespace std;

void insertAtBottom(Stack<int> &st, int first,int second)
{
    if(st.empty())
    {
        if(first > second)
        {
            st.push(second);
            st.push(first);
        }
        else
        {
            st.push(first);
            st.push(second);
        }
        return;
    }

    int first2 = st.pop();
    int second2 = st.pop();

    insertAtBottom(st,first,second);
    if(first2 > second2)
    {
        st.push(second2);
        st.push(first2);
    }
    else
    {
        st.push(first2);
        st.push(second2);
    }
}

void sortStack(Stack<int> &st)
{
    if(st.empty()) return;
    int first = st.pop();
    int second = st.pop();
    sortStack(st);
    insertAtBottom(st,first,second);
}

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

    sortStack(st);

    while(!st.empty()) cout<<st.pop()<<" ";

    return 0;
}

