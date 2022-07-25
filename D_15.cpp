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

    int maxNum=array[0],minNum=array[0],maxIndex=0,minIndex=0;
    for(int i=0; i<size; i++){
        if(array[i]>maxNum){
            maxNum = array[i];
            maxIndex = i;
        }
        if(array[i]<minNum){
            minNum = array[i];
            minIndex = i;
        }
    }

    cout<<"Max: "<<maxNum<<", Index: "<<maxIndex<<endl;
    cout<<"Min: "<<minNum<<", Index: "<<minIndex<<endl;

    return 0;
}

