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

struct Test
{
    int position[1000];
};

void insertAtTail(Node* &head, int val);
void insertAtHead(Node* &head, int val);
void insertAtMiddle(Node* &head,int position, int val);
int countLinkedList(Node* &head);
int searchByValueUnique(Node* &head, int key);
void searchByValueDuplicate(Node* &head, int key);
Test searchByValueDuplicateReturn(Node* &head, int key);
void insertionByValueUnique(Node* &head, int searchValue, int value);
void insertValueWithDuplicateValue(Node* &head, int searchValue, int value);
void deletionAtHead(Node* &head);
void deletionAtTail(Node* &head);
void deletionAtSpecificPosition(Node* &head, int position);
void deletionByValueUnique(Node* &head, int val);
void deletionByValueDuplicate(Node* &head, int val);
Node *reverseNonRecursive(Node *&head);
Node *reverseRecursive(Node *&head);
void display(Node* n);


void insertAtTail(Node* &head, int val)
{
    Node *newNode = new Node(val);
    if(head==NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->Next!=NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}

void insertAtHead(Node* &head, int val)
{
    Node* newNode = new Node(val);
    newNode->Next = head;
    head = newNode;
}

void insertAtMiddle(Node* &head,int position, int val)
{
    Node* temp = head;
    int count=1;
    while(temp->Next!=NULL && count<=position-1)
    {
        count++;
        temp = temp->Next;
    }
    Node* newNode = new Node(val);
    newNode->Next = temp->Next;
    temp->Next = newNode;
}

int countLinkedList(Node* &head)
{
    int count = 1;
    Node* temp = head;
    if(temp==NULL) return 0;
    while(temp->Next!=NULL)
    {
        count++;
        temp=temp->Next;
    }
    return count;
}

int searchByValueUnique(Node* &head, int key)
{
    Node* temp = head;
    int count = 1;
    if(temp==NULL) return -1;
    while(temp->value != key)
    {
        if(temp->Next == NULL) return -1;
        temp = temp->Next;
        count++;
    }
    return count;
}

void searchByValueDuplicate(Node* &head, int key)
{
    Node* temp = head;
    int size;
    size = countLinkedList(head);
    int position[size+1], k = 1;
    int count = 1;
    int flag = 0;

    while(temp!=NULL)
    {
        if(temp->value == key)
        {
            position[k] = count;
            k++;
            flag = 1;
        }
        temp = temp->Next;
        count++;
    }

    if(flag==0) cout<<"The Searched value is not yet in the List"<<endl;
    else
    {
        position[0] = k;
        cout<<"The value is found at Position: ";
        for(int i=1; i<position[0]; i++)
        {
            cout<<position[i];
            if(i<position[0]-1) cout<<", ";
        }
        cout<<endl;
    }
}

Test searchByValueDuplicateReturn(Node* &head, int key)
{
    Node* temp = head;
    Test T;
    int k = 1;
    int count = 1;

    while(temp!=NULL)
    {
        if(temp->value == key)
        {
            T.position[k] = count;
            k++;
        }
        temp = temp->Next;
        count++;
    }
    T.position[0] = k;
    return T;
}

void insertionByValueUnique(Node* &head, int searchValue, int value)
{
    int position;
    position = searchByValueUnique(head, searchValue);
    insertAtMiddle(head, position, value);
}

void insertValueWithDuplicateValue(Node* &head, int searchValue, int value)
{
    Test T;
    T = searchByValueDuplicateReturn(head,searchValue);
    for(int i=1; i<T.position[0]; i++) insertAtMiddle(head, T.position[i]+i-1, value);
}

void deletionAtHead(Node* &head)
{
    Node* temp=head;
    if(temp != NULL)
    {
        head=temp->Next;
        delete temp;
    }
    else cout<<"There is no value in the Linked List"<<endl;
}

void deletionAtTail(Node* &head)
{
    Node* temp=head;
    if(temp!=NULL && temp->Next!=NULL)
    {
        while(temp->Next->Next!=NULL)
        {
            temp=temp->Next;
        }
        Node *delNode = temp->Next;
        temp->Next = NULL;
        delete delNode;
    }
    else
    {
        if(temp==NULL) cout<<"There is no value in the Linked List"<<endl;
        else deletionAtHead(head);
    }
}

void deletionAtSpecificPosition(Node* &head, int position)
{
    Node *temp = head;
    if(temp!=NULL && position<=countLinkedList(head))
    {
        if(position==1)
        {
            deletionAtHead(head);
        }
        else if(position==countLinkedList(head))
        {
            deletionAtTail(head);
        }
        else
        {

            int i = 1;
            while(i<position-1)
            {
                temp=temp->Next;
                i++;
            }
            Node *delNode = temp->Next;
            temp->Next = delNode->Next;
            delete delNode;
        }
    }
    else
    {
        if(position>countLinkedList(head)) cout<<"Position Out of Bound"<<endl;
        else cout<<"There is no value in the Linked List"<<endl;
    }
}

void deletionByValueUnique(Node* &head, int val)
{
    int position = searchByValueUnique(head, val);
    if(position==-1) cout<<"Value not Found in the Linked List"<<endl;
    else deletionAtSpecificPosition(head, position);
}

void deletionByValueDuplicate(Node* &head, int val)
{
    Test T = searchByValueDuplicateReturn(head, val);
    if(T.position[0]==1) cout<<"There is no value in the Linked List"<<endl;
    else
    {
        for(int i=1; i<T.position[0]; i++)
        {
            deletionAtSpecificPosition(head, T.position[i]+1-i);
        }
    }
}

Node *reverseNonRecursive(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    if(head==NULL)
    {
        cout<<"Liked List is empty"<<endl;
        return head;
    }
    Node *next = head->Next;

    while(true)
    {
        current->Next = prev;
        prev = current;
        current = next;
        if(current==NULL) break;
        next=next->Next;
    }
    return prev;
}

Node *reverseRecursive(Node *&head)
{
    if(head==NULL || head->Next==NULL)
    {
        if(head==NULL) cout<<"Linked list is empty"<<endl;
        return head;
    }

    Node *newHead = reverseRecursive(head->Next);
    head->Next->Next = head;
    head->Next = NULL;

    return newHead;
}

void display(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->value;
        if(n->Next!=NULL) cout<<" -> ";
        n = n->Next;
    }
    cout<<endl;
}

int main()
{
    int value, position, delValue, searchValue;
    Node* head = NULL;

    cout<<"Choice 1: Insertion at Head"
        <<endl<<"Choice 2: Insertion at Tail"
        <<endl<<"Choice 3: Insertion at Middle"
        <<endl<<"Choice 4: Total Length of LinkedList"
        <<endl<<"Choice 5: Search a unique value from LinkedList"
        <<endl<<"Choice 6: Search a duplicate value from LinkedList"
        <<endl<<"Choice 7: Insertion after a specific value(Unique List)"
        <<endl<<"Choice 8: Insertion after a specific value(Duplicate Enable)"
        <<endl<<"Choice 9: Deletion at Head"
        <<endl<<"Choice 10: Deletion at Tail"
        <<endl<<"Choice 11: Deletion at Specific Position"
        <<endl<<"Choice 12: Deletion by value(Unique List)"
        <<endl<<"Choice 13: Deletion by value(Duplicate Enable)"
        <<endl<<"Choice 14: Reversal of List Non-Recursive"
        <<endl<<"Choice 15: Reversal of List Recursive"
        <<endl<<"Choice 0: Exit"<<endl;
    cout<<"Choice: ";
    int choice;
    cin>>choice;

    while(choice != 0)
    {
        switch(choice)
        {
        case 1:
            cout<<"Enter the value: ";
            cin>>value;
            insertAtHead(head,value);
            break;
        case 2:
            cout<<"Enter the value: ";
            cin>>value;
            insertAtTail(head,value);
            break;
        case 3:
            cout<<"Enter the Desired Position: ";
            cin>>position;
            cout<<"Enter the value: ";
            cin>>value;
            insertAtMiddle(head, position, value);
            break;
        case 4:
            cout<<"Linked List Length: "<<countLinkedList(head)<<endl;
            break;
        case 5:
            cout<<"Enter the Value to Search: ";
            cin>>value;
            position = searchByValueUnique(head,value);
            if(position!=-1) cout<<"The number is at Position "<<position<<endl;
            else cout<<"The number is not yet in the List"<<endl;
            break;
        case 6:
            cout<<"Enter the Value to Search: ";
            cin>>value;
            //searchByValueDuplicate(head, value);
            Test T;
            T = searchByValueDuplicateReturn(head, value);
            if(T.position[0]==1) cout<<"The Searched value is not yet in the List"<<endl;
            else
            {
                int size=T.position[0];
                cout<<"The value is found at Position: ";
                for(int i=1; i<size; i++)
                {
                    cout<<T.position[i];
                    if(i<size-1) cout<<", ";
                }
                cout<<endl;
            }
            break;
        case 7:
            cout<<"Enter the Value to Search: ";
            cin>>searchValue;
            cout<<"Enter the Value to insert: ";
            cin>>value;
            insertionByValueUnique(head, searchValue, value);
            break;
        case 8:
            searchValue;
            cout<<"Enter the Value to Search: ";
            cin>>searchValue;
            cout<<"Enter the Value to insert: ";
            cin>>value;
            insertValueWithDuplicateValue(head, searchValue, value);
            break;
        case 9:
            deletionAtHead(head);
            break;
        case 10:
            deletionAtTail(head);
            break;
        case 11:
            cout<<"Enter the Desired Position: ";
            cin>>position;
            deletionAtSpecificPosition(head, position);
            break;
        case 12:
            cout<<"Enter the value to Delete: ";
            cin>>delValue;
            deletionByValueUnique(head, delValue);
        case 13:
            cout<<"Enter the value to Delete: ";
            cin>>delValue;
            deletionByValueDuplicate(head, delValue);
            break;
        case 14:
            head = reverseNonRecursive(head);
            break;
        case 15:
            head = reverseRecursive(head);
            break;
        default:
            break;
        }
        cout<<"Next Choice: ";
        cin>>choice;
    }

    cout<<"Linked List: ";
    display(head);
    cout<<endl;
    return 0;
}
