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

void insertAtTail(Node* &head, int val);
void insertAtHead(Node* &head, int val);
void insertAtMiddle(Node* &head,int position, int val);
void display(Node* n);


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

void insertAtHead(Node* &head, int val)
{
    Node* newNode = new Node(val);
    newNode->Next = head;
    head = newNode;
}

void insertAtMiddle(Node* &head,int position, int val)
{
    Node* temp = head;
    int count=1;
    while(temp->Next!=NULL && count<=position-1)
    {
        count++;
        temp = temp->Next;
    }
    Node* newNode = new Node(val);
    newNode->Next = temp->Next;
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
    int value,position;
    Node* head = NULL;

    cout<<"Choice 1: Insertion at Head"
        <<endl<<"Choice 2: Insertion at Tail"
        <<endl<<"Choice 0: Exit"<<endl;
    cout<<"Choice: ";
    int choice;
    cin>>choice;

    while(choice != 0)
    {
        switch(choice)
        {
        case 1:
            cout<<"Enter the value: ";
            cin>>value;
            insertAtHead(head,value);
            break;
        case 2:
            cout<<"Enter the value: ";
            cin>>value;
            insertAtTail(head,value);
            break;
        case 3:
            cout<<"Enter the Desired Position: ";
            cin>>position;
            cout<<"Enter the value: ";
            cin>>value;
            insertAtMiddle(head, position, value);
            break;
        default:
            break;
        }
        cout<<"Next Choice: ";
        cin>>choice;
    }

    cout<<"Linked List: ";
    display(head);
    cout<<endl;
    return 0;
}
