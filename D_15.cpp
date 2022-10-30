#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size1;
    cout<<"Enter the array size: ";
    cin>>size1;
    int array1[size1];

    for(int i=0; i<size1; i++) cin>>array1[i];

    int array2[size1], index=0;
    for(int i=0; i<size1; i++){
        int found = 0;
        for(int j=0; j<index; j++)
            if(array1[i]==array2[j]) found = 1;
        if(found == 0){
            array2[index] = array1[i];
            index++;
        }
    }

    for(int i=0; i<index; i++) cout<<array2[i]<<" ";
    cout<<endl;

    return 0;
}

