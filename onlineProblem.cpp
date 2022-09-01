#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        string str;
        cin>>str;
        if(n==5)
        {
            int arr[n]= {0}, flag=0;
            for(int i=0; i<n; i++)
                if(str[i]=='T' || str[i]=='i' || str[i]=='m' || str[i]=='u' || str[i]=='r') arr[i]++;

            for(int i=0; i<n; i++)
            {
                if(arr[i]!=1)
                {
                    flag=1;
                    break;
                }
            }
            flag==0 ? cout<<"YES"<<endl : cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
        t--;
    }
    return 0;
}
