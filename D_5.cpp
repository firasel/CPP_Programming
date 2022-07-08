#include<iostream>
#include<string.h>
using namespace std;
int main(){
    char str[27];
    cin>>str;
    int arr[26]={0};
    for(int i=0; i<strlen(str); i++)
        arr[str[i]-'a']++;
    for(int i=0; i<26; i++){
        if(arr[i]>1){
            cout<<"no"<<endl;
            return 0;
        }
    }
    cout<<"yes"<<endl;
    return 0;
}
