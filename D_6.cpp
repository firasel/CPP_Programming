#include<iostream>
using namespace std;

int main(){
    int row,col,sum=0;
    cin>>row>>col;
    int a[row][col];

    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            cin>>a[i][j];

    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            if(i==j) sum+=a[i][j];
    cout<<"Diagonal Sum = "<<sum<<endl;
    return 0;
}
