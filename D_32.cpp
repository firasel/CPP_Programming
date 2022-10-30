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

void insertAtTail(doublyNode* &head, int val);
void insertAtHead(doublyNode* &head, int val);
void insertAtSpecific(doublyNode* &head, int position, int val);
int searchValueUnique(doublyNode* &head, int val);
int searchAtSpecific(doublyNode* &head, int position);
int countLinkedList(doublyNode* &head);

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
    if(head==NULL){
        head=newNode;
        return;
    }
    head->Prev = newNode;
    newNode->Next = head;
    head = newNode;
}

void insertAtSpecific(doublyNode* &head, int position, int val)
{
    if(position==1)
    {
        insertAtHead(head, val);
        return;
    }
    if(position>=countLinkedList(head))
    {
        insertAtTail(head, val);
        return;
    }
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

int countLinkedList(doublyNode* &head)
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

int searchValueUnique(doublyNode* &head, int val)
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

int searchAtSpecific(doublyNode* &head, int position)
{
    int count = 1;
    doublyNode *temp = head;
    if(position<1 || countLinkedList(head)<position) return -1;
    while(temp!=NULL && count!=position)
    {
        temp=temp->Next;
        count++;
    }
    return temp->Value;
}

int main()
{
    int n;
    cin>>n;
    doublyNode *head=NULL;

    for(int i=1; i<=n; i++)
    {
        int pre,nex;
        cin>>pre>>nex;

        if(nex==0 && pre!=0)
        {
            int search = searchValueUnique(head,i);
            if(search!=-1)
            {
                if(searchAtSpecific(head,search-1)!=pre)
                    insertAtSpecific(head, search-1, pre);
            }
            else
            {
                insertAtHead(head,i);
                insertAtHead(head,pre);
            }
        }
        else if(pre==0 && nex!=0)
        {
            int search = searchValueUnique(head,i);
            if(search!=-1)
            {
                if(searchAtSpecific(head, search+1)!=nex)
                    insertAtSpecific(head, search+1, nex);
            }
            else
            {
                insertAtTail(head,i);
                insertAtTail(head,nex);
            }
        }
        else if(pre==0 && nex==0) insertAtHead(head,i);
        else
        {
            int search = searchValueUnique(head,i);
            if(search!=-1)
            {
                if(searchAtSpecific(head, search+1)!=nex)
                    insertAtSpecific(head, search+1, nex);
                if(searchAtSpecific(head,search-1)!=pre)
                    insertAtSpecific(head, search, pre);
            }
            else
            {
                insertAtTail(head,pre);
                insertAtTail(head,i);
                insertAtTail(head,nex);
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        int search = searchValueUnique(head,i);
        int prevValue = searchAtSpecific(head,search-1);
        int prev = (prevValue==-1) ? 0 : prevValue;
        int nextValue = searchAtSpecific(head,search+1);
        int next = (nextValue==-1) ? 0 : nextValue;

        cout<<prev<<" "<<next<<endl;
    }

    return 0;
}
