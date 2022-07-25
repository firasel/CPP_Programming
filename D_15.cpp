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
    int checkValue;
    cin>>checkValue;

    int findPos[size],index=0,found=0;
    for(int i=0; i<size; i++){
        if(array[i]==checkValue){
            found=1;
            findPos[index] = i;
            index++;
        }
    }

    if(found==0) cout<<"NOT FOUND"<<endl;
    else{
        cout<<"FOUND at index position: ";
        for(int i=0; i<index; i++)
            cout<<findPos[i]<<" ";
    }

    return 0;
}

