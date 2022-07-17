#include<bits/stdc++.h>
using namespace std;

int main()
{
    string st="ab   ab cd   cd xy xy";
    stringstream stream(st);

    string w;
    while(stream>>w)
    {
        cout<<w<<endl;
    }

    return 0;
}
