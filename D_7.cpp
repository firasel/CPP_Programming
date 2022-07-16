#include<bits/stdc++.h>
using namespace std;

class Student
{
public:
    char name[100];
    int roll;
};

int main()
{
    Student jahed;
    strcpy(jahed.name,"Mr. Jahed");
    jahed.roll = 22;

    cout<<jahed.name<<" "<<jahed.roll<<endl;
    return 0;
}
