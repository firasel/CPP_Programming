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
int countLinkedList(Node *&head);
void insertAtSpecificPosition(Node *&head, int position, int val);
int searchValueUnique(Node *&head, int val);
void makeCycle(Node *&head, int pos);
bool detectCycle(Node* &head);
void removeCycle(Node *&head);

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

int countLinkedList(Node *&head)
{
    int count=0;
    Node *temp=head;
    while(temp!=NULL)
    {
        temp=temp->Next;
        count++;
    }
    return count;
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

int searchValueUnique(Node *&head, int val)
{
    int count=0;
    Node *temp = head;
    while(temp!=NULL)
    {
        count++;
        if(temp->value == val)
        {
            return count;
        }
        temp=temp->Next;
    }
    return -1;
}

void makeCycle(Node *&head, int pos)
{
    Node* temp = head;
    Node* startNode;
    int count = 1;

    while(temp->Next!=NULL)
    {
        if(count==pos) startNode=temp;
        temp=temp->Next;
        count++;
    }
    temp->Next=startNode;
}

bool detectCycle(Node* &head)
{
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->Next != NULL && fast->Next->Next != NULL)
    {
        slow = slow->Next;
        fast = fast->Next->Next;
        // Cycle check
        if(slow->Next==fast->Next) return true;
    }
    return false;
}

void removeCycle(Node *&head)
{
    Node* slow = head;
    Node* fast = head;

    do
    {
        slow = slow->Next;
        fast = fast->Next->Next;
    }
    while(slow!=fast);

    fast=head;

    while(fast->Next!=slow->Next)
    {
        slow=slow->Next;
        fast=fast->Next;
    }
    slow->Next=NULL;
}

int main()
{
    int choice, val, position;
    Node *head = NULL;

    cout<<"Choice 1: Print Linked List"<<endl
        <<"Choice 2: Insert a value At Tail"<<endl
        <<"Choice 3: Insert a value At Head"<<endl
        <<"Choice 4: Insert a value At Specific Position"<<endl
        <<"Choice 5: Length of Linked List"<<endl
        <<"Choice 6: Search a value(Unique List)"<<endl
        <<"Choice 7: Make Cycle"<<endl
        <<"Choice 8: Detect Cycle"<<endl
        <<"Choice 9: Remove a Cycle"<<endl
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
        case 4:
            cout<<"Enter the position: ";
            cin>>position;
            if(countLinkedList(head)>0 && countLinkedList(head)>=position && position>0)
            {
                cout<<"Enter the value: ";
                cin>>val;
                insertAtSpecificPosition(head, position, val);
            }
            else cout<<"Wrong position entered, Try again"<<endl;
            break;
        case 5:
            cout<<"Length of LinkedList: "<<countLinkedList(head)<<endl;
            break;
        case 6:
            if(head==NULL) cout<<"List is empty"<<endl;
            else
            {
                cout<<"Enter the value: ";
                cin>>val;
                int result = searchValueUnique(head, val);
                if(result>0) cout<<val<<" is at "<<result<<" Position"<<endl;
                else cout<<"Not found"<<endl;
            }
            break;
        case 7:
            cout<<"Enter the position: ";
            cin>>position;
            makeCycle(head, position);
            break;
        case 8:
            if(detectCycle(head)) cout<<"There is a Cycle in the List"<<endl;
            else cout<<"There is no Cycle in the List"<<endl;
            break;
        case 9:
            if(detectCycle(head)) removeCycle(head);
            else cout<<"There is no Cycle in the List"<<endl;
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

