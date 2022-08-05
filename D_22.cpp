#include<bits/stdc++.h>
using namespace std;

void printArr(int arr[],int st, int n)
{
    for(int i=st; i<=n; i++) cout<<arr[i]<<" ";
}

int binarySearch(int array[], int x, int lb, int ub)
{
    cout<<"LB: "<<lb<<" UB: "<<ub<<endl;
    if(lb<=ub)
    {
        int mid =(lb+ub)/2;
        cout<<"Mid: "<<mid<<endl;
        // Center
        if(x==array[mid])
        {
            cout<<"Find: ";
            printArr(array,mid,mid);
            cout<<endl;
            return mid;
        }
        // Right side
        else if(x > array[mid])
        {
            cout<<"Right Side: ";
            printArr(array, mid+1, ub);
            cout<<endl;
            binarySearch(array, x, mid+1, ub);
        }
        // Left side
        else
        {
            cout<<"Left Side: ";
            printArr(array, lb, mid-1);
            cout<<endl;
            binarySearch(array, x, lb, mid-1);
        }

    }
    else return -1;
}

int main()
{
    int n=10;
    int arr[n] = {1, 2, 9, 11, 17, 24, 26, 31, 32, 45};
    cout<<"Array: ";
    printArr(arr,0,n-1);
    cout<<endl;

    int indexNumber;
    indexNumber = binarySearch(arr, 6, 0, n-1);
    if(indexNumber != -1) cout<<"Index No: "<<indexNumber<<" Position No: "<<indexNumber+1<<endl;
    else cout<<"Not Found!"<<endl;

    return 0;
}

