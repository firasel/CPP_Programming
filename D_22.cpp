#include<bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n)
{
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
}

int main()
{
    int n=6;
    int arr[n] = {5, 1, 3, 8, 2, 2};
    cout<<"Array: ";
    printArr(arr,n);
    cout<<endl;

    for(int i=1; i<n; i++)
    {
        cout<<i<<" Step: ";
        printArr(arr,n);
        cout<<"-> ";
        int key = arr[i];
        int j = i-1;
        while(arr[j]>key && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
            printArr(arr,n);
            cout<<"-> ";
        }
        arr[j+1] = key;
        printArr(arr,n);
        cout<<endl;
    }

    cout<<"After Sort: ";
    printArr(arr,n);

    return 0;
}

