#include<bits/stdc++.h>
using namespace std;

class Parent
{
public:
    int x;
private:
    int y;
protected:
    int z;
public:
    Parent(int a, int b, int c){
        x=a;
        y=b;
        z=c;
    }
};

class Child: public Parent
{
public:
    int xx;
    Child(int aa, int a, int b, int c) : Parent(a, b, c)
    {
        xx=aa;
    }
    void tellMe(){
        cout<<"Protected value: "<<z<<endl;
    }
};

int main()
{
    Parent pt(10,20,30);
    Child ch(100,5,15,25);
    ch.tellMe();
    cout<<ch.x<<' '<<pt.x<<endl;
    return 0;
}
