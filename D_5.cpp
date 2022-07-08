#include<iostream>
#include<string.h>
using namespace std;
int main(){
    char o[51],e[51];
    cin>>o>>e;
    int j=0,k=0;
    for(int i=0; i<strlen(o)+strlen(e); i++){
        if(i%2==0){
            cout<<o[j];
            j++;
        }else{
            cout<<e[k];
            k++;
        }
    }
    cout<<endl;
    return 0;
}
