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

void displayList(doublyNode *&head);
void insertAtTail(doublyNode *&head, int val);
void insertAtHead(doublyNode *&head, int val);
int countLinkedList(doublyNode *&head);
void displayReverseList(doublyNode *&head);

void displayList(doublyNode *&head)
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

void insertAtTail(doublyNode *&head, int val)
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

void insertAtHead(doublyNode *&head, int val)
{
    doublyNode *newNode = new doublyNode(val);
    head->Prev = newNode;
    newNode->Next = head;
    head = newNode;
}

int countLinkedList(doublyNode *&head)
{
    int count=0;
    doublyNode *temp=head;
    while(temp!=NULL)
    {
        temp=temp->Next;
        count++;
    }
    return count;
}

void displayReverseList(doublyNode *&head)
{
    doublyNode *temp = head;
    while(temp->Next!=NULL) temp=temp->Next;

    while(temp!=NULL)
    {
        cout<<temp->Value;
        if(temp->Prev != NULL) cout<<" -> ";
        temp=temp->Prev;
    }
    cout<<endl;
}

int main()
{
    int choice, val, position;
    doublyNode *head = NULL;

    cout<<"Choice 1: Print Linked List"<<endl
        <<"Choice 2: Insert a value At Tail"<<endl
        <<"Choice 3: Insert a value At Head"<<endl
        <<"Choice 4: Length of Linked List"<<endl
        <<"Choice 5: Reverse Print"<<endl
        <<"Choice 0: Exit Program"<<endl;

    cout<<"Choice: ";
    cin>>choice;
    while(choice!=0)
    {
        switch(choice)
        {
        case 1:
            cout<<"Doubly Linked List: ";
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
        case 4:
            cout<<"Length of Doubly Linked List: "<<countLinkedList(head)<<endl;
            break;
        case 5:
            cout<<"Doubly Linked List: ";
            displayReverseList(head);
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

