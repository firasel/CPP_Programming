#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size1, size2;
    cout<<"Enter the first array size: ";
    cin>>size1;
    int array1[size1];

    for(int i=0; i<size1; i++) cin>>array1[i];

    cout<<"Enter the second array size: ";
    cin>>size2;
    int array2[size2];

    for(int i=0; i<size2; i++) cin>>array2[i];


    int findPos[size1>size2 ? size1 : size2],index=0,found=0;
    for(int i=0; i<size1; i++){
        for(int j=0; j<size2; j++){
            if(array1[i]==array2[j]){
                found=1;
                findPos[index] = array1[i];
                index++;
            }
        }
    }

    if(found==0) cout<<"Empty set"<<endl;
    else{
        for(int i=0; i<index; i++)
            cout<<findPos[i]<<" ";
        cout<<endl;
    }

    return 0;
}

