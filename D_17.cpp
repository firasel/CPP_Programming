#include<iostream>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        int n,q;
        cin.ignore();
        cin>>n>>q;
        int arr[n];
        for(int j=0; j<n; j++) cin>>arr[j];
        cout<<"Case "<<i<<":\n";
        for(int j=0; j<q; j++){
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            int minNum = arr[a];
            for(int k=a+1; k<=b; k++)
                if(arr[k]<minNum) minNum = arr[k];
            cout<<minNum<<"\n";
        }
    }
    return 0;
}
