#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int num = x, rem=0;
        double revNum=0;
        while(num>0){
            rem=num%10;
            revNum=revNum*10+rem;
            num/=10;
        }
        return revNum==x;
    }
};

int main()
{
    Solution st;
    if(st.isPalindrome(121)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    return 0;
}

