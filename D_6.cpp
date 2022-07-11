#include<iostream>
using namespace std;

int main(){
    int row,col,sum=0;
    cin>>row>>col;
    int a[row][col];

    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            cin>>a[i][j];

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(a[i][j] != a[j][i]){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }

    cout<<"Yes"<<endl;
    return 0;
}
