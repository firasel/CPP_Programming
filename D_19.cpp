#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n][n],majorArr[n],minorArr[n];

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>arr[i][j];


    for(int i=0; i<n; i++)
    {
        majorArr[i] = arr[i][i];
        minorArr[i] = arr[i][n-i-1];
    }

    cout<<"Major diagonal: ";
    for(int i=0; i<n; i++)
        cout<<majorArr[i]<<" ";
    cout<<endl;

    cout<<"Minor diagonal: ";
    for(int i=0; i<n; i++)
        cout<<minorArr[i]<<" ";
    cout<<endl;

    return 0;
}

