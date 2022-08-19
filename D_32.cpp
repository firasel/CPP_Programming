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
void displayList(Node *head);void replaceEvenNumber(Node *&head);

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

void replaceEvenNumber(Node *&head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        if(temp->value%2==0) temp->value=-1;
        temp=temp->next;
    }
}

int main()
{
    int n;
    cin>>n;
    Node *head = NULL;
    for(int i=0; i<n; i++)
    {
        int val;
        cin>>val;
        insertAtTail(head, val);
    }

    replaceEvenNumber(head);

    displayList(head);
    cout<<endl;
    return 0;
}

