#include<bits/stdc++.h>
using namespace std;

int main(){
    int a=100;
    int b=200;
    int minValue = min(a,b);
    int maxValue = max(a,b);
    cout<<"Min: "<<minValue<<endl<<"Max: "<<maxValue<<endl;
    cout<<a<<' '<<b<<endl;
    swap(a,b);
    cout<<a<<' '<<b<<endl;

    return 0;
}
