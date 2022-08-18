#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c=0;
    cin>>a>>b;
    if(a%2==1 || b%2==1) c=((b-a)/2)+1;
    else c=(b-a)/2;
    cout<<c<<endl;
    return 0;
}

