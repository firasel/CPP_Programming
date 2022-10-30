#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node* next;
    Node(int val)
    {
        value = val;
        next=NULL;
    }
};

void insertAtTail(Node* &head, int val)
{
    Node* newNode = new Node(val);
    if(head==NULL) head=newNode;
    else
    {
        Node* temp = head;
        while(temp->next!=NULL) temp = temp->next;
        temp->next = newNode;
    }
}

void displayList(Node* &head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->value<<" ";
        temp=temp->next;
    }
}

void modifyList(Node* &head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        if(temp->value%2==0) temp->value = -1;
        temp=temp->next;
    }
}

void printMiddle(Node* &head)
{
    Node* firstNode = head;
    Node* secondNode = head;
    if(head!=NULL)
    {
        while(secondNode!=NULL && secondNode->next!=NULL)
        {
            secondNode = secondNode->next->next;
            firstNode = firstNode->next;
        }
        cout<<"Middle element is "<<firstNode->value<<endl;
    }
}

int main()
{
    Node* head = NULL;
    int n,val;
    cin>>n;
    while(n)
    {
        cin>>val;
        insertAtTail(head,val);
        n--;
    }

    cout<<"Linked List: ";
    displayList(head);
    cout<<endl;

    printMiddle(head);

    return 0;
}

