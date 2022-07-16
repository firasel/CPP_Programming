#include<bits/stdc++.h>
using namespace std;

class Student
{
public:
    int x;
    void findNum(){
        cout<<"Number is "<<x<<endl;
    }
};

int main()
{
    Student exst;
    exst.x = 22;

    exst.findNum();
    return 0;
}
