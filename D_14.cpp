#include<bits/stdc++.h>
using namespace std;

int binarySearch(int array[], int x, int lb, int ub)
{
    if(lb<=ub){
        int mid =(lb+ub)/2;
        // Center
        if(x==array[mid]) return mid;
        // Right side
        else if(x > array[mid]) binarySearch(array, x, mid+1, ub);
        // Left side
        else binarySearch(array, x, lb, mid-1);

    }else return -1;
}

int main()
{
    int size;
    cin>>size;

    int array[size];
    for (int i=0; i<size; i++)
        cin>>array[i];
    int checkValue;
    cout<<"Please enter the you want to search: ";
    cin>>checkValue;

    int indexNumber;
    indexNumber = binarySearch(array, checkValue, 0, size-1);
    if(indexNumber != -1) cout<<"Index No: "<<indexNumber<<" Position No: "<<indexNumber+1<<endl;
    else cout<<"Not Found!"<<endl;
    return 0;
}
