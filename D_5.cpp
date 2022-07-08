#include<iostream>
#include<string.h>
using namespace std;
int main(){
    char str[101];
    cin>>str;
    cout<<str[0]<<strlen(str)-2<<str[strlen(str)-1]<<endl;
    return 0;
}
