#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char str[n];
    cin>>str;
    int x=0,a=0;
    for(int i=0; i<n; i++){
        str[i] == 'I' ? x++ : x--;
        x>a && (a=x);
    }
    cout<<a<<endl;
    return 0;
}
