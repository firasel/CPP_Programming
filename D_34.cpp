#include<bits/stdc++.h>
#include"MY_QUEUE.h"

using namespace std;

void insertElement(Queue<int> &qu, int n)
{
    for(int i=0; i<n; i++)
    {
        int val;
        cin>>val;
        qu.push(val);
    }
}

int findFrequency(Queue<int> &qu, int n, int key){
    int count = 0;
    for(int i=0; i<n; i++){
        if(qu.Front()==key) count++;
        qu.push(qu.Front());
        qu.pop();
    }
    return count;
}

int main()
{
    Queue <int> qu;
    Queue <int> freq;
    int n,m;
    cin>>n;
    insertElement(qu, n);
    cin>>m;
    insertElement(freq, m);

    while(!freq.empty()){
        int count = findFrequency(qu, n, freq.pop());
        count > 0 ? cout<<count<<endl : cout<<-1<<endl;
    }

    return 0;
}

