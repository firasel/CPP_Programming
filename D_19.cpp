#include<bits/stdc++.h>
using namespace std;

bool checkValue(int arr[], int n, int key)
{
    for(int i=0; i<n; i++)
        if(arr[i]==key) return true;
    return false;
}

int main()
{
    int m,n;
    cin>>m>>n;
    int arr[m][n],arr2[m*n];
    memset(arr2,0,sizeof(arr2));

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>arr[i][j];

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(checkValue(arr2,m*n,arr[i-1][j-1])) arr[i-1][j-1] = -1;
            else arr2[i*j-1] = arr[i-1][j-1];
        }
    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}

