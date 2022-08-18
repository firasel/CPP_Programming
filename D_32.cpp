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

    int uniqueArr[m*n],k=0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            int flag = 0;
            for(int l=0; l<k; l++)
            {
                if(uniqueArr[l]==arr[i][j])
                {
                    arr[i][j] = -1;
                    flag = 1;
                    break;
                }
            }

            if(flag==0)
            {
                uniqueArr[k] = arr[i][j];
                k++;
            }
        }
    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            cout<<arr[i][j];
        cout<<endl;
    }

    return 0;
}

