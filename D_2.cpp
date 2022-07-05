#include<iostream>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    (a*b == c*d) ? cout<<a*b<<endl : (a*b > c*d) ? cout<<a*b<<endl : cout<<c*d<<endl;
    return 0;
}
