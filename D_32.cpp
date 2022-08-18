#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t){
        int n,q;
        cin>>n;
        int earns[n],shoppings[n];

        for(int i=0; i<n; i++) cin>>earns[i];
        for(int i=0; i<n; i++) cin>>shoppings[i];

        cin>>q;
        while(q)
        {
            int d;
            cin>>d;
            int remaining=0;
            for(int i=0; i<=d; i++) remaining += earns[i]-shoppings[i];
            (remaining>=0) ? cout<<1<<" " : cout<<0<<" ";
            q--;
        }

        t--;
    }

    return 0;
}

