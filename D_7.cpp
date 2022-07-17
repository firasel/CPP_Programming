#include<bits/stdc++.h>
using namespace std;

class Parent
{
private:
    int taka;
public:
    Parent(int tk){
        taka=tk;
    }
    friend class ParentFriend;
};

class ParentFriend
{
public:
    void tellSecret(Parent *ptr){
        cout<<ptr->taka<<endl;
    }
};

int main()
{
    Parent pt(1203);
    ParentFriend fd;
    fd.tellSecret(&pt);
    return 0;
}
