#include<bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    string str="235813";
    for(int i=0; i<str.length()-2; i++)
    {
        int a=str[i]-'0', b=str[i+1]-'0', c=str[i+2]-'0';
        if(a+b!=c){
            cout<<a<<" "<<b<<" "<<c<<endl;
            cout<<"False"<<endl;
            return 0;
        }
    }
    cout<<"True"<<endl;
    return 0;
}

