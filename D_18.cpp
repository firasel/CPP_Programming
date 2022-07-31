#include<bits/stdc++.h>
using namespace std;

void printArray(int array[], int n){
    for(int i=0; i<n; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int size;
    cin>>size;

    int array[size];

    for(int i=0; i<size; i++) cin>>array[i];

    cout<<"Before Sort: ";
    printArray(array,size);

    // Step 1
    int max=INT_MIN;
    for(int i=0; i<size; i++)
        if(array[i] > max)
            max = array[i];

    // Step 2
    int count[max+1];
    for(int i=0; i<=max; i++) count[i]=0;

    // Step 3
    for(int i=0; i<size; i++) count[array[i]]++;

    // Step 4
    for(int i=1; i<=max; i++) count[i] += count[i-1];

    // Step 5
    int final[size];
    for(int i=size-1; i>=0; i--){
        count[array[i]]--;
        int k = count[array[i]];
        final[k] = array[i];
    }

    cout<<"After Sort: ";
    printArray(final,size);

    return 0;
}

