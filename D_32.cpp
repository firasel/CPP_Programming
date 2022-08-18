#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;

    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cin>>m;
    int arr2[m];
    for(int i=0; i<m; i++) cin>>arr2[i];

    int size = m+n;
    int finalArr[size];
    fill(finalArr,finalArr+size,0);
    int k=0;

    for(int i=0; i<n; i++)
    {
        int flag=0;
        for(int j=0; j<m; j++)
        {
            if(arr[i]==arr2[j])
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
        {
            finalArr[k] = arr[i];
            k++;
        }
    }

    for(int i=0; i<k; i++) cout<<finalArr[i]<<" ";

    return 0;
}

