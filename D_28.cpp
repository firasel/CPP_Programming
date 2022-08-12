#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    for (int i=0; i <= n; i++)
    {
        for (int j=0; j < n; j++)
        {
            if (i== n/2 || i-j == n/2 || i+j == n/2)
                cout <<"* ";
            else
                cout <<" ";
        }
        cout << endl;
    }

    cout << endl<<endl<<endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=n-i; j>0; j--) cout<<" ";
        for(int j=0; j<i; j++) cout<<"*";
        cout<<endl;
    }
    for(int i=1; i<=2; i++)
    {
        for(int j=0; j<n*2; j++) cout<<"*";
        cout<<endl;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<i; j++) cout<<" ";
        for(int j=n-i; j>0; j--) cout<<"*";
        cout<<endl;
    }
    return 0;
}

