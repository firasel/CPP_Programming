#include<bits/stdc++.h>
using namespace std;

int main()
{
    string st="Hello world";
    cout<<st.length()<<endl;
    cout<<st.size()<<endl;
    cout<<st<<' '<<st.size()<<endl;
    st.resize(5);
    cout<<st<<' '<<st.size()<<endl;
    st.clear();
    cout<<st<<' '<<st.size()<<endl;
    st.empty() ? cout<<"Yes"<<endl : cout<<"No"<<endl;
    return 0;
}
