#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int val)
    {
        value = val;
        next = NULL;
    }
};

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(Node *n)
{
    while (n != NULL)
    {
        cout << n->value;
        if (n->next != NULL)
            cout << " -> ";
        n = n->next;
    }
    cout << endl;
}

void makeCycle(Node *&head, int pos)
{
    Node *temp = head;
    Node *startNode;
    int count = 1;

    while (temp->next != NULL)
    {
        if (count == pos)
            startNode = temp;
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

bool detectCycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        if (slow->next == fast->next->next)
            return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

int main()
{
    int n;
    Node *head = NULL;
    cout << "Enter the length: ";
    cin >> n;
    while (n)
    {
        int val;
        cin >> val;
        insertAtTail(head, val);
        n--;
    }
    display(head);
    makeCycle(head, 2);
    cout << detectCycle(head) << endl;

    return 0;
}
