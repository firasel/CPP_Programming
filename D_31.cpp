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
void insertAtSpecificPosition(Node *&head, int position, int val);
void rotateSpecificPosition(Node *&head, int k);

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

void insertAtSpecificPosition(Node *&head, int position, int val)
{
    int count = 1;
    Node *temp = head;
    if(position==1)
    {
        insertAtHead(head, val);
        return;
    }
    Node *newNode = new Node(val);
    while(temp!=NULL && count<position-1)
    {
        temp=temp->Next;
        count++;
    }
    newNode->Next = temp->Next;
    temp->Next = newNode;
}

void rotateSpecificPosition(Node *&head, int k)
{
    int count = 0,position = 1;
    Node *temp = head;
    Node *kthNode = NULL;
    while(temp!=NULL)
    {
        count++;
        if(count==k) kthNode = temp;
        if(count>k)
        {
            insertAtSpecificPosition(head,position,temp->value);
            position++;
        }
        temp=temp->Next;
    }
    kthNode->Next=NULL;
}

int main()
{
    int n, val, k;
    Node *head = NULL;

    cout<<"Enter the elements number: ";
    cin>>n;
    while(n)
    {
        cin>>val;
        insertAtTail(head, val);
        n--;
    }

    cout<<"Enter the position: ";
    cin>>k;

    rotateSpecificPosition(head, k);

    cout<<"After rotate Linked List: ";
    displayList(head);

    return 0;
}

