#include<bits/stdc++.h>
using namespace std;

class doublyNode
{
public:
    int Value;
    doublyNode *Prev;
    doublyNode *Next;

    doublyNode(int val)
    {
        Value = val;
        Prev = NULL;
        Next = NULL;
    }
};

void displayList(doublyNode* &head);
void insertAtTail(doublyNode* &head, int val);
void insertAtHead(doublyNode* &head, int val);


void displayList(doublyNode* &head)
{
    doublyNode *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->Value;
        if(temp->Next != NULL) cout<<" -> ";
        temp=temp->Next;
    }
    cout<<endl;
}

void insertAtTail(doublyNode* &head, int val)
{
    doublyNode *temp = head;
    doublyNode *newNode = new doublyNode(val);
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
    newNode->Prev = temp;
}

void insertAtHead(doublyNode* &head, int val)
{
    doublyNode *newNode = new doublyNode(val);
    head->Prev = newNode;
    newNode->Next = head;
    head = newNode;
}

int main()
{
    int choice, val, position;
    doublyNode *head = NULL;

    insertAtTail(head, 12);
    insertAtTail(head, 16);
    insertAtTail(head, 28);
    insertAtTail(head, 25);
    insertAtTail(head, 53);

    displayList(head);
    cout<<endl;
    cout<<head->Next->Next->Value<<endl;

    return 0;
}
