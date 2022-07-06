#include<bits/stdc++.h>
using namespace std;
void change(int *x){
    *x=*x*2;
}

int main()
{
    int a=10;
    int *p=&a;
    change(p);
    cout<<a<<endl;

    return 0;
}
