#include<bits/stdc++.h>
using namespace std;

int main()
{
    string st="Hello world";
    cout<<st.front()<<' '<<st.at(6)<<' '<<st.back()<<endl;
    st.assign("Hi");
    cout<<st<<endl;

    string st1="Hello";
    string st2="World";
    st1.append(st2);
    st1.push_back('A');
    st1.push_back('B');
    st1.pop_back();
    st1.insert(5," W ");
    st1.erase(6,2);
    cout<<st1<<endl;

    string st3="First";
    string st4="Second";
    swap(st3,st4);
    cout<<st3<<' '<<st4<<endl;
    return 0;
}
