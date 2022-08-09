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

void displayList(Node *&head);
void insertAtTail(Node *&head, int val);
void insertAtHead(Node *&head, int val);

void displayList(Node *&head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->value<<" ";
        temp=temp->Next;
    }
    cout<<endl;
}

void insertAtTail(Node *&head, int val)
{
    Node *temp = head;
    Node *newNode = new Node(val);
    if(temp==NULL)
    {
        head = newNode;
        return;
    }

    while(temp->Next!=NULL)
    {
        temp=temp->Next;
    }
    temp->Next = newNode;
}

void insertAtHead(Node *&head, int val)
{
    Node *temp = head;
    Node *newNode = new Node(val);
    if(temp==NULL)
    {
        head = newNode;
        return;
    }
    newNode->Next = head;
    head = newNode;
}

int main()
{
    int choice, val;
    Node *head = NULL;

    cout<<"Choice 1: Print Linked List"<<endl
        <<"Choice 2: Insert a value At Tail"<<endl
        <<"Choice 3: Insert a value At Head"<<endl
        <<"Choice 0: Exit Program"<<endl;

    cout<<"Choice: ";
    cin>>choice;
    while(choice!=0)
    {
        switch(choice)
        {
        case 1:
            cout<<"Linked List: ";
            displayList(head);
            break;
        case 2:
            cout<<"Enter the value: ";
            cin>>val;
            insertAtTail(head, val);
            break;
        case 3:
            cout<<"Enter the value: ";
            cin>>val;
            insertAtHead(head, val);
            break;
        default:
            cout<<"Wrong input! Please input a valid option number."<<endl;
            break;
        }
        cout<<"Next Choice: ";
        cin>>choice;
    }

    return 0;
}

