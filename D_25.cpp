#include<bits/stdc++.h>
using namespace std;

class positionList
{
public:
    int value;
    positionList *next;
    positionList(int val)
    {
        value = val;
        next = NULL;
    }
};

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
void insertAtSpecific(doublyNode *&head, int position, int val);
int searchValueUnique(doublyNode *&head, int val);
positionList* searchValueDuplicat(doublyNode *&head, int val);
void displayPositionList(positionList *&head);

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

void insertAtSpecific(doublyNode *&head, int position, int val)
{
    int count = 1;
    doublyNode *temp = head;
    doublyNode *newNode = new doublyNode(val);
    while(temp!=NULL && count!=position-1)
    {
        temp=temp->Next;
        count++;
    }
    newNode->Next = temp->Next;
    newNode->Prev = temp;
    temp->Next->Prev = newNode;
    temp->Next = newNode;
}

int searchValueUnique(doublyNode *&head, int val)
{
    int pos=0;
    doublyNode *temp = head;
    while(temp!=NULL)
    {
        pos++;
        if(temp->Value==val)
        {
            return pos;
        }
        temp=temp->Next;
    }
    return -1;
}

positionList* searchValueDuplicat(doublyNode *&head, int val)
{
    int pos=0;
    doublyNode* temp = head;
    positionList* positionHead = NULL;
    while(temp!=NULL)
    {
        pos++;
        if(temp->Value==val)
        {
            positionList *newNode = new positionList(pos);
            if(positionHead==NULL) positionHead = newNode;
            else
            {
                positionList *temp2 = positionHead;
                while(temp2->next!=NULL) temp2=temp2->next;
                temp2->next = newNode;
            }
        }
        temp=temp->Next;
    }
    return positionHead;
}

void displayPositionList(positionList *&head)
{
    positionList *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->value;
        if(temp->next != NULL) cout<<" ";
        temp=temp->next;
    }
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
        <<"Choice 6: Insert at specific position"<<endl
        <<"Choice 7: Search a value(Unique List)"<<endl
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
        case 6:
            cout<<"Enter the Position: ";
            cin>>position;
            cout<<"Enter the value: ";
            cin>>val;
            insertAtSpecific(head, position, val);
            break;
        case 7:
            cout<<"Enter the value: ";
            cin>>val;
            position = searchValueUnique(head, val);
            if(position!=-1)cout<<val<<" is found at "<<position<<endl;
            else cout<<val<<" is not found"<<endl;
            break;
        case 8:
        {
            cout<<"Enter the value: ";
            cin>>val;
            positionList *positionHead = searchValueDuplicat(head, val);
            if(positionHead==NULL) cout<<val<<" is not found"<<endl;
            else
            {
                cout<<val<<" is found at: ";
                displayPositionList(positionHead);
                cout<<endl;
            }
            break;
        }
        default:
            cout<<"Wrong input! Please input a valid option number."<<endl;
            break;
        }
        cout<<"Next Choice: ";
        cin>>choice;
    }

    return 0;
}

