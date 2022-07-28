#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    std::ios::sync_with_stdio(false);
    cin>>tc;
    for(int t=0; t<tc; t++)
    {
        int n,q;
        cin>>n>>q;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        cout<<"Case "<<t+1<<":\n";
        for(int i=0; i<q; i++)
        {
            int k;
            cin>>k;
            if(k==1)
            {
                int p;
                cin>>p;
                cout<<arr[p]<<"\n";
                arr[p]=0;
            }
            else if(k==2)
            {
                int p,m;
                cin>>p>>m;
                arr[p]+=m;
            }
            else if(k==3)
            {
                int s,e,sum=0;
                cin>>s>>e;
                for(s; s<=e; s++) sum+=arr[s];
                cout<<sum<<"\n";
            }
        }
    }

    return 0;
}
