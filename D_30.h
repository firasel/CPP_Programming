#include<bits/stdc++.h>
using namespace std;

template <typename N> class Node
{
public:
    N value;
    Node* next;
    Node* prev;
    Node(N val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};

template <typename S> class Stack
{
    Node <S> *head;
    Node <S> *top;
    int count=0;
public:
    Stack()
    {
        head = NULL;
        top = NULL;
    }

    void push(S val)
    {
        Node <S> *newNode = new Node <S> (val);
        count++;

        if(head==NULL)
        {
            head = top = newNode;
            return;
        }

        top->next = newNode;
        newNode->prev = top;
        top = newNode;
    }

    S pop()
    {
        Node <S> *delNode = top;
        S chk;

        if(head==NULL)
        {
            cout<<"Stack Underflow"<<endl;
            return chk;
        }

        chk = delNode->value;
        count--;

        if(top==head)
        {
            head = top = NULL;
            delete delNode;
            return chk;
        }

        top=delNode->prev;
        top->next=NULL;
        delete delNode;
        return chk;
    }

    bool empty()
    {
        if(head==NULL) return true;
        else return false;
    }

    int size()
    {
        return count;
    }

    S Top()
    {
        if(top==NULL)
        {
            cout<<"Stack Underflow | There is no Element in the Top"<<endl;
        }
        else return top->value;
    }
};

