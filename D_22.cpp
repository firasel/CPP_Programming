#include<bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n)
{
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
}

int main()
{
    int arr[6] = {7, 2, 13, 2, 11, 4};
    for(int i=1; i<=6; i++)
    {
        cout<<i<<" Iteration:"<<endl;
        for(int j=0; j<5; j++)
        {
            cout<<j+1<<" Step: ";
            printArr(arr,6);
            cout<<" -> ";
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            printArr(arr,6);
            cout<<endl;
        }
    }

    return 0;
}

