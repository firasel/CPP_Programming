#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[5] = {5,6,4,8,2};
    sort(arr,arr+5);
    for(int i=0; i<5; i++)
        cout<<arr[i]<<' ';
    cout<<endl;

    return 0;
}
