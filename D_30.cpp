#include<bits/stdc++.h>
#include"D_30.h"

using namespace std;

int prefixEvaluation(string prefixStr)
{
    Stack<int> st;
    for(int i=prefixStr.length()-1; i>=0; i--)
    {
        switch(prefixStr[i])
        {
        case '+':
        {
            int a=int(st.pop());
            int b=int(st.pop());
            st.push(a+b);
            break;
        }
        case '-':
        {
            int a=int(st.pop());
            int b=int(st.pop());
            st.push(a-b);
            break;
        }
        case '*':
        {
            int a=int(st.pop());
            int b=int(st.pop());
            st.push(a*b);
            break;
        }
        case '/':
        {
            int a=int(st.pop());
            int b=int(st.pop());
            st.push(a/b);
            break;
        }
        default :
        {
            st.push(prefixStr[i]-'0');
            break;
        }
        }
    }
    return st.pop();
}

int main()
{

    string prefixStr = "-+7*45+20";
    cout<<prefixEvaluation(prefixStr)<<endl;

    return 0;
}

