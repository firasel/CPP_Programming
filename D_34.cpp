#include<bits/stdc++.h>
#include"D_30.h"

using namespace std;

int main()
{
    Stack <char> st;
    string str = "[{{()}}(){()}][[()]]{()}";

    for(int i=0; i<str.length(); i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[') st.push(str[i]);
        else
        {
            if((str[i]==')' && st.Top()!='(') || (str[i]=='}' && st.Top()!='{') || (str[i]==']' && st.Top()!='[') )
            {
                cout<<"NO"<<endl;
                return 0;
            }
            st.pop();
        }
    }

    if(st.empty()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

