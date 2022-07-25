#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cout<<"Enter the array size: ";
    cin>>size;

    int array[size];

    for(int i=0; i<size; i++)
        cin>>array[i];

    for(int i=0; i<size/2; i++){
        int temp = array[size-i-1];
        array[size-i-1] = array[i];
        array[i] = temp;
    }

    for(int i=0; i<size; i++)
        cout<<array[i]<<" ";
    cout<<endl;

    return 0;
}

