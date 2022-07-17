#include<bits/stdc++.h>
using namespace std;

int main()
{
    string st="Hello world";
    cout<<st.find('l')<<' '<<st.find_first_of('o')<<' '<<st.find_last_of('o')<<endl;
    cout<<st.find_first_not_of('H')<<' '<<st.find_last_not_of('d')<<endl;
    cout<<st.substr(2,8)<<endl;

    return 0;
}
