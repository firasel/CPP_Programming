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
void removeDuplicateValue(Node *&head);

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

void removeDuplicateValue(Node *&head)
{
    Node *temp = head;
    Node *head2 = NULL;
    while(temp!=NULL)
    {
        if(temp->Next==NULL || temp->value!=temp->Next->value)
        {
            insertAtTail(head2,temp->value);
        }
        temp=temp->Next;
    }
    head=head2;
}

int main()
{
    int n, val;
    Node *head = NULL;

    cout<<"Enter the elements number: ";
    cin>>n;
    while(n)
    {
        cin>>val;
        insertAtTail(head, val);
        n--;
    }
    removeDuplicateValue(head);
    cout<<"Unique Linked List: ";
    displayList(head);

    return 0;
}

