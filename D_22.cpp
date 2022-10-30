#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node * next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node * &head, int val)
{
    Node *newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node *tmp = head;
    while(tmp->next!=NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void insertAthead(Node* &head, int val)
{
    Node *newHead = new Node(val);
    newHead->next = head;
    head = newHead;
}

void reversedListPrint (Node* head)
{
    if (head == NULL) return;
    reversedListPrint(head->next);
    cout<<head->data<<" ";
}

void display(Node * head)
{
    Node * tmp = head;
    while(tmp!=NULL)
    {
        cout<<tmp->data;
        if(tmp->next!=NULL) cout<<"->";
        tmp = tmp->next;
    }
    cout<<endl;
}

int main ()
{
    Node* head = NULL;
    insertAtTail(head,5);
    insertAthead(head,15);
    insertAtTail(head,25);
    display(head);

    cout<<"Print in reverse way: "<<endl;
    reversedListPrint(head);
    return 0;
}
