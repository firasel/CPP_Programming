#include <bits/stdc++.h>
using namespace std;

template <typename N> class Node
{
public:
    N value;
    Node *next;
    Node *prev;
    Node(N val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};

template<typename S> class Stack
{
    Node<S> * head;
    Node<S> * top;
    Node<S> * Mid;
    int count =0;
public:
    Stack()
    {
        head = NULL;
        top = NULL;
        Mid = NULL;
    }
    void push(S val)
    {
        Node<S> *newNode = new Node<S>(val);
        if(head == NULL)
        {
            head = top = Mid = newNode;
            count++;
            return;
        }
        if(count % 2 == 0)
        {
            Mid = Mid->next;
        }
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        count++;
    }

    S pop()
    {
        Node<S> *delnode;
        delnode = top;
        S chk;
        if(head == NULL)
        {
            cout<<"Stack underflow"<<endl;
            return chk;
        }
        else if(top == head)
        {
            head = top = NULL;
        }
        else
        {
            top = delnode->prev;
            top->next = NULL;
        }
        count--;
        if(count&1)
        {
            Mid = Mid->prev;
        }
        chk = delnode->value;
        delete delnode;
        return chk;
    }

    S Top()
    {
        S chk;
        if(head == NULL)
        {
            cout<<"Stack underflow"<<endl;
        }
        else chk = top->value;
        return chk;
    }

    bool Empty()
    {
        if(head == NULL)
        {
            return true;
        }
        else return false;
    }

    int Size()
    {
        return count;
    }

    S mid()
    {
        S chk;
        if(head == NULL)
        {
            cout<<"Stack is empty"<<endl;
            return chk;
        }
        chk = Mid->value;
        return chk;
    }
};

