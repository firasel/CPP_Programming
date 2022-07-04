#include<bits/stdc++.h>

using namespace std;

namespace one
{
    void fun()
    {
        cout<<"Hello world 1"<<endl;
    }
}

namespace two
{
    void fun()
    {
        cout<<"Hello world 2"<<endl;
    }
}

int main()
{
    char a[15]="Hello world";
    cout<<a<<endl;

    int b,c;
    cin>>b>>c;
    cout<<b<<' '<<c<<endl;

    char str[50];
    cin>>str;
    cout<<str<<endl;

    char str2[50];
    cin.getline(str2,50);
    cout<<str2<<endl;

    int num[5];
    for(int i=0; i<5; i++)
        cin>>num[i];
    for(int i=0; i<5; i++)
        cout<<num[i]<<' ';
    cout<<endl;

    double e=11.2365;
    int f=int(e);
    cout<<f<<endl;

    one::fun();
    two::fun();

    return 0;
}
