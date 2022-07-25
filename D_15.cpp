#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cout<<"Enter the array size: ";
    cin>>size;

    int array[size];
    int sum=0;
    for(int i=0; i<size; i++)
    {
        cin>>array[i];
        sum+=array[i];
    }
    cout<<sum<<endl;

    return 0;
}

