#include<bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n)
{
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
}

int main()
{
    int n=8;
    int arr[n] = {7, 2, 9, 2, 7, 4, 5, 1};
    cout<<"Array: ";
    printArr(arr,n);
    cout<<endl;

    // Step 1
    int max=INT_MIN;
    for(int i=0; i<n; i++)
        if(arr[i] > max)
            max = arr[i];

    // Step 2
    int count[max+1];
    for(int i=0; i<=max; i++) count[i]=0;

    // Step 3
    for(int i=0; i<n; i++) count[arr[i]]++;
    cout<<"Count: ";
    printArr(count,max+1);
    cout<<endl;
    // Step 4
    for(int i=1; i<=max; i++) count[i] += count[i-1];
    cout<<"Count Sum: ";
    printArr(count,max+1);
    cout<<endl;

    // Step 5
    int final[n];
    for(int i=0; i<n; i++) final[i]=0;

    for(int i=n-1; i>=0; i--)
    {
        printArr(final,n);
        cout<<" -> ";
        count[arr[i]]--;
        int k = count[arr[i]];
        final[k] = arr[i];
        printArr(final,n);
        cout<<endl;
    }

    cout<<"After Sort: ";
    printArr(final,n);

    return 0;
}

