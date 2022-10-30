#include<bits/stdc++.h>
#include"MY_QUEUE.h"
using namespace std;

typedef pair <int, int> mytype;

int main()
{
    Queue <mytype> q;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int c1, c2;
        cin>>c1>>c2;
        q.push(make_pair(c1, c2));
    }

    mytype front = q.Front();
    mytype back = q.Back();

    if(!q.empty()) cout<<"Front: "<<front.first<<" "<<front.second<<endl<<endl;
    if(!q.empty()) cout<<"Back: "<<back.first<<" "<<back.second<<endl<<endl;

    while(!q.empty()){
        mytype chk = q.pop();
        cout<<chk.first<<" "<<chk.second<<endl;
    }

    return 0;
}
