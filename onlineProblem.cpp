#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> salary={8000, 9000, 2000, 3000, 6000, 1000};
    sort(salary.begin(),salary.end());
    double sum=0;
    for(int i=1; i<salary.size()-1; i++) sum+=salary.at(i);
    cout<<sum/(salary.size()-2)<<endl;

    return 0;
}
