#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size1;
    cout<<"Enter the array size: ";
    cin>>size1;
    int array1[size1];

    for(int i=0; i<size1; i++)
    {
        cin>>array1[i];
        if(array1[i]%3==0)
        {
            array1[i] = -1;
        }
    }

    for(int i=0; i<size1; i++)
        cout<<array1[i]<<" ";
    cout<<endl;

    return 0;
}

