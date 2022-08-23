#include<bits/stdc++.h>
#include"D_30.h"

using namespace std;

void insertElement(Stack <int> &st, int n)
{
    for(int i=0; i<n; i++)
    {
        int val;
        cin>>val;
        st.push(val);
    }
}

void stackSort(Stack <int> &st)
{
    Stack <int> temp;
    while(!st.empty())
    {
        int tmp = st.Top();
        st.pop();

        while(!temp.empty() && temp.Top() > tmp)
        {
            st.push(temp.Top());
            temp.pop();
        }
        temp.push(tmp);
    }


    st = temp;
}

int main()
{
    Stack <int> st;
    int n;
    cin>>n;
    insertElement(st, n);
    stackSort(st);

    while(!st.empty()) cout<<st.pop()<<" ";
    cout<<endl;

    return 0;
}

