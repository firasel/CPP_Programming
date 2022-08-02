#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;

    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};

void insertAtTail(Node* &head, int val)
{
    Node *newNode = new Node(val);
    if(head==NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while(temp->Next!=NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}

void display(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->value;
        if(n->Next!=NULL) cout<<" -> ";
        n = n->Next;
    }
    cout<<endl;
}

int main()
{
    int n;
    Node* head = NULL;
    char choice= 'Y';
    while(choice=='Y')
    {
        cout<<"Enter the value: ";
        cin>>n;
        insertAtTail(head,n);
        cout<<"Do you want to continue: (Y/N) ";
        cin>>choice;
    }

    display(head);

    return 0;
}

