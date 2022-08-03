#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    int arr[m][n];

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>arr[i][j];

    int maxNum=arr[0][0];
    int a=0;
    int b=0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(maxNum<arr[i][j])
            {
                maxNum=arr[i][j];
                a=i;
                b=j;
            }
        }
    }

    cout<<"Max: "<<maxNum<<endl<<"Location: ["<<a<<"]["<<b<<"]"<<endl;
    return 0;
}

