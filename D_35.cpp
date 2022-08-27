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
    int count = 0;
    if(temp==NULL)
    {
        head = newNode;
        return;
    }

    while(temp->Next!=NULL)
    {
        count++;
        temp=temp->Next;
    }

    int sum = temp->Value;

    if(val<0)
    {
        while(temp!=NULL)
        {
            cout<<temp->Value<<" "<<count<<endl;
            if((sum+val)==0)
            {
                cout<<"ZERO"<<endl;
                // delete
                return;
            }
            temp=temp->Prev;
            sum+=temp->Value;
        }
    }

    temp->Next = newNode;
    newNode->Prev = temp;
}

int main()
{
    int choice, val, position;
    doublyNode *head = NULL;

    cout<<"Choice 1: Print Linked List"<<endl
        <<"Choice 2: Insert a value At Tail"<<endl
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
        default:
            cout<<"Wrong input! Please input a valid option number."<<endl;
            break;
        }
        cout<<"Next Choice: ";
        cin>>choice;
    }

    return 0;
}
