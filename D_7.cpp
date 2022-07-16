#include<bits/stdc++.h>
using namespace std;

class Example
{
private:
    int x,y,z;
public:
    Example(int a, int b, int c){
        x=a;
        y=b;
        z=c;
    }
    void printNum(){
        cout<<x<<' '<<y<<' '<<z<<endl;
    }
    void setter(int a){
        x=a;
    }
    int getter(){
        return x;
    }
};

int main()
{
    Example a(10, 20, 30);
    a.printNum();
    a.setter(25);
    cout<<a.getter()<<endl;
    return 0;
}
