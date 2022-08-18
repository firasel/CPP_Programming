#include<bits/stdc++.h>
#include"D_30.h"

using namespace std;

void removeMidElement(Stack<int> &st, int mid, int count)
{
    if(count>mid) return;
    int topElement = st.pop();
    removeMidElement(st, mid, count+1);
    if(count!=mid) st.push(topElement);
}

void insertAtBottom(Stack<int> &st, int chkElement)
{
    if(st.empty()){
        st.push(chkElement);
        return;
    }

    int topElement = st.pop();
    insertAtBottom(st,chkElement);
    st.push(topElement);
}

void reverseStack(Stack<int> &st)
{
    if(st.empty()) return;
    int topElement = st.pop();
    reverseStack(st);
    insertAtBottom(st,topElement);
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

    reverseStack(st);
    removeMidElement(st, (n/2)+1, 1);

    while(!st.empty()) cout<<st.pop()<<" ";

    return 0;
}

