#include<iostream>
using namespace std;

int main(){
    int row,col,sum=0;
    cin>>row>>col;
    int a[row][col];

    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            cin>>a[i][j];

    if(row!=col){
        cout<<"No"<<endl;
        return 0;
    }else{
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(i==j) continue;
                if(a[i][j]>0){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
    }
    int temp;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(i==j){
                if(i==0 && j==0) temp = a[i][j];
                else{
                    if(temp != a[i][j]){
                        cout<<"Not scalar"<<endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout<<"Scalar"<<endl;

    return 0;
}
