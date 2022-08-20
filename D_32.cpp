#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int val)
    {
        value=val;
        next=NULL;
    }

};

void insertAtTail(Node *&head, int val);
void displayList(Node *head);
void deleteNodeSequentially(Node *&head, int m, int n);

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if(head==NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newNode;
}

void displayList(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->value;
        if(head->next!=NULL) cout<<" -> ";
        head=head->next;
    }
}

void deleteNodeSequentially(Node *&head, int m, int n)
{
    Node *temp = head;
    int i=1;
    while(temp!=NULL)
    {
        for(i; (i<m && temp!=NULL); i++) temp=temp->next;

        for(int j=0; (j<n && temp!=NULL); j++)
        {
            Node *delNode = temp->next;
            if(delNode!=NULL) temp->next = delNode->next;
            delete delNode;
        }

        i=0;
    }
}

int main()
{
    int size,m,n;
    cin>>size>>m>>n;
    Node *head = NULL;
    for(int i=0; i<size; i++)
    {
        int val;
        cin>>val;
        insertAtTail(head, val);
    }

    deleteNodeSequentially(head,m,n);

    displayList(head);
    cout<<endl;
    return 0;
}

