#include<bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n>=2) cout<<"2 ";
    if(n>=3) cout<<"3 ";
    for(int i=1; i<n/2; i++)
    {
        if((6*i)-1<=n) cout<<(6*i)-1<<" ";
        else break;
        if((6*i)+1<=n) cout<<(6*i)+1<<" ";
        else break;
    }
    cout<<endl;
    return 0;
}

