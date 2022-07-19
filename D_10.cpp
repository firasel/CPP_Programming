#include<bits/stdc++.h>
using namespace std;

class BankAccount
{
public:
    string accout_holder;
    string address;
    int age;
    int account_number;
protected:
    int balance;
private:
    string password;
    BankAccount(string accout_holder, string address, int age, string password)
    {
        this -> accout_holder = accout_holder;
        this -> address = address;
        this -> age = age;
        this -> password = password;
        this -> account_number = rend()%1000000000;
        cout<<"Your account no is "<<this->account_number<<endl;
    }
};

int main()
{

    return 0;
}
