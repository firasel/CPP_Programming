#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int sqrtValue = sqrt(n);
    int arr[sqrtValue][sqrtValue];

    for(int i=0; i<sqrtValue; i++)
        for(int j=0; j<sqrtValue; j++)
            cin>>arr[i][j];

    for(int i=0; i<sqrtValue; i++)
    {
        for(int j=0; j<sqrtValue; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}

