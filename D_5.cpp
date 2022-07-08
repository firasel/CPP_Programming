#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,total=0;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    sort(arr,arr+n,std::greater<int>());
    for(int i=0; i<k; i++)
        total+=arr[i];
    cout<<total<<endl;
    return 0;
}
