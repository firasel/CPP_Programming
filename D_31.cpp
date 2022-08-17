#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    char value;
    Node *Next;
    Node(char val)
    {
        value = val;
        Next = NULL;
    }
};

void displayList(Node *&head);
void insertAtTail(Node *&head, char val);
bool checkPalidrome(Node *&head);
void reverseLinkedList(Node *&head);

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

void insertAtTail(Node *&head, char val)
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

void reverseLinkedList(Node *&head)
{
    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->Next;
        current->Next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

bool checkPalidrome(Node *&head)
{
    Node *temp = head;
    Node *head2 = NULL;
    while(temp!=NULL)
    {
        insertAtTail(head2,temp->value);
        temp=temp->Next;
    }

    reverseLinkedList(head2);
    temp = head;

    while(temp!=NULL)
    {
        if(temp->value!=head2->value) return false;
        temp = temp->Next;
        head2 = head2->Next;
    }
    return true;
}

int main()
{
    int n;
    char val;
    Node *head = NULL;
    cout<<"Enter total characters length: ";
    cin>>n;
    while(n)
    {
        cin>>val;
        insertAtTail(head, val);
        n--;
    }

    if(checkPalidrome(head)) cout<<"True"<<endl;
    else cout<<"False"<<endl;

    return 0;
}

